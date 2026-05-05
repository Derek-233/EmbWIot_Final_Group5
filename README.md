# EmbWIoT Final Project — Group 5
## BLE Angle-of-Arrival Navigation System

**Team:** Qingyuan Cao · Jonathan Lee · Shyun Lee
**Date:** May 5, 2026

**Full Project Slides (PDF):** [v2_0505_EmbWIoT_Project_Group5.pdf](docs/v2_0505_EmbWIoT_Project_Group5.pdf)

The report documents the complete project progression:
- **Slides 2–3:** Motivation — robot navigation using wireless signals, BLE contribution
- **Slides 4–5:** Hardware Setup — XPLR-AOA-3 first-time setup and subsequent use
- **Slides 6–8:** Experiment Setup — azimuth/elevation axis definition, LOS/NLOS methodology
- **Slides 9–13:** AoA Accuracy Test — elevation and azimuth LOS vs NLOS measurement charts
- **Slides 14–18:** Localization Test — setup, LOS and NLOS results with geometry plots
- **Slides 19–20:** ROS2 Integration — package structure, build/launch output, live data verification
- **Slides 21–22:** Robot Experiment Setup — Stretch SE3 with EVB-ANT-1, 6-point coordinate measurement
- **Slides 23–27:** Tag Localization on Robot — method, results (LOS 10.1 cm, NLOS 32.6 cm), LOS/NLOS comparison
- **Slide 28:** Deliverables — project goals and completion status

---

## Introduction

This project extends a WiFi-based robot navigation system with BLE Angle-of-Arrival (AoA) localization using the u-blox XPLR-AOA-3 platform on a Hello Robot Stretch SE3. BLE AoA enables instance-level target identification via MAC address and sub-meter localization even when the target is not visually observable.

**Key results:**
- Bench AoA accuracy: LOS error within **±4°**, NLOS error up to **±32°** (shifts toward 0°)
- Robot localization: LOS Euclidean error **10.1 cm**, NLOS **32.6 cm** (excluding outlier point14)
- AoA measurement std: **~2.4°** (Az_new), **~3.6°** (El_new) under LOS

---

## Performance summary

All measurements taken in the project test room (Stretch 3 with EVB-ANT-1 mounted on robot, C209 tag on tripod).

| Metric | Value | How measured |
|---|---|---|
| AoA sample rate (throughput) | ~20 Hz | Average inter-sample period on `/aoa/measurement` over a 60 s window |
| AoA accuracy (azimuth, LOS) | ±4° (mean error) | Bench test, ground-truth tape measure, points 1–6 |
| AoA accuracy (elevation, LOS) | ±4° (mean error) | Bench test, points 1–6 |
| AoA accuracy (NLOS, drywall obstruction) | up to ±32° (biased toward 0°) | Same setup as LOS with wall between tag and antenna |
| AoA std deviation (LOS) | 2.4° azimuth · 3.6° elevation | Stationary tag, 30 s capture |
| Localization error (LOS) | **10.1 cm** Euclidean | 6-anchor LSQ, points 7–12, tag at (0, 300) cm |
| Localization error (NLOS) | **32.6 cm** Euclidean (excl. point14 outlier) | 6-anchor LSQ, points 13–18, tag at (–318, 285) cm |
| Tested range | up to ~5 m anchor↔tag separation | Point14 at 4.59 m lateral was the boundary case (near ±90° antenna FOV) |
| RF band | 2.4 GHz ISM (BLE 5.1, 37 advertising channels) | u-locateEmbed default config |
| Tag energy | CR2032 (~225 mAh) at default advertising interval | Manufacturer spec; lifetime not measured in this project |
| Anchor power | USB-bus-powered (5 V, EVB-ANT-1) | No battery; current draw not measured |

**Latency note:** end-to-end latency from BLE packet reception to ROS topic publish was not measured; the dominant delay is the u-locateEmbed angle computation on the RT1061, which runs synchronously per advertising event. As a rough upper bound, sample period = 1/20 Hz = 50 ms.

---

## Hardware

| Component | Model / Details | Link |
|-----------|-----------------|------|
| BLE direction-finding kit | u-blox XPLR-AOA-3 | [u-blox.com/en/product/xplr-aoa-3-kit](https://www.u-blox.com/en/product/xplr-aoa-3-kit) |
| Antenna board | u-blox ANT-B10 — 8-element patch antenna array, hosts NINA-B411 BLE 5.1 module | [u-blox.com/en/product/ant-b10](https://www.u-blox.com/en/product/ant-b10) |
| Application/anchor board | u-blox EVB-ANT-1 — NXP RT1061 MCU, runs u-locateEmbed AoA algorithm | included in XPLR-AOA-3 kit |
| BLE module (anchor) | u-blox NINA-B411 (Bluetooth 5.1, on ANT-B10) | [u-blox.com/en/product/nina-b41-series](https://www.u-blox.com/en/product/nina-b41-series-open-cpu) |
| BLE tag | u-blox C209 (NINA-B406 / nRF52833), CR2032 battery | [u-blox.com/en/product/c209-aoa-tag](https://www.u-blox.com/en/product/c209-aoa-tag) · [tag firmware repo](https://github.com/u-blox/c209-aoa-tag) |
| Robot platform | Hello Robot Stretch 3 (referred to as "Stretch SE3" in slides) | [hello-robot.com/stretch-3-product](https://hello-robot.com/stretch-3-product) |
| Host (bench experiments) | Windows PC, COM11, 115200 baud, CTS/RTS | — |
| Host (robot experiments) | Ubuntu 22.04 on Stretch onboard NUC, `/dev/ttyUSB2` | — |

### Hardware modifications / configuration

- **EVB-ANT-1 J2 jumper** set to position **F (FTDI)** — exposes the NINA-B411 UART through the on-board FTDI to USB. This is a configuration jumper, not a permanent rework.
- **EVB-ANT-1 J12** left open (no jumper).
- **C209 tag** flashed with `release_for_dfu_boot.zip` (u-blox-supplied firmware, see [c209-aoa-tag releases](https://github.com/u-blox/c209-aoa-tag/releases)). No custom firmware was developed for this project.
- No custom PCBs, no enclosure modifications. The EVB-ANT-1 was mounted to the Stretch top plate using existing M4 inserts and a 3D-printed bracket.

### RF specifications

| Parameter | Value |
|-----------|-------|
| RF band | 2.4 GHz ISM |
| Bluetooth version | 5.1 (with Constant Tone Extension for direction finding) |
| Advertising rate | ~20 Hz (u-locateEmbed default) |
| Anchor antenna | 8-element patch array (ANT-B10), measures az/el ±90° |
| Tag antenna | NINA-B406 integrated PCB antenna |
| TX power (tag) | u-locateEmbed default (~0 dBm typical) — exact value not configured by us |
| Compliance | XPLR-AOA-3 kit is FCC/CE pre-certified for evaluation use only (per u-blox kit documentation) |

### Power subsystem

- **Tag:** single CR2032 lithium coin cell (~225 mAh nominal). The tag consumes ~50–100 µA average at default advertising parameters per the [u-blox C209 application repo](https://github.com/u-blox/c209-aoa-tag) — projected battery life on the order of months. Not directly measured in this project.
- **Anchor:** USB-bus-powered (5 V) via USB-C from the host; no battery, no charging circuit. The EVB-ANT-1 includes onboard regulators for the RT1061 MCU and ANT-B10 supply rails.

---

## Software environment

### Toolchain versions

| Tool | Version | Notes |
|------|---------|-------|
| OS (host) | Ubuntu 22.04.4 LTS | onboard Stretch NUC |
| Python | 3.10.12 | Ubuntu 22.04 default |
| ROS 2 | Humble Hawksbill (Patch Release 7) | apt: `ros-humble-desktop` |
| colcon | 0.16.x (`colcon-common-extensions` from apt) | for ROS 2 build |
| gcc / g++ | 11.4.0 | Ubuntu 22.04 default |
| Python packages | see `requirements.txt` (direct) and `requirements-lock.txt` (full tree) | |
| s-center (Windows, bench setup only) | s-center classic v6.10 or later | from u-blox.com, NINA-B series |
| u-locateEmbed firmware (anchor) | v2.x (factory pre-flashed on EVB-ANT-1) | not modified |
| C209 tag firmware | `release_for_dfu_boot.zip` from `u-blox/c209-aoa-tag` GitHub releases | flashed via s-center DFU |

### Radio stack configuration

All radio parameters use u-locateEmbed defaults — we did not modify the PHY, channel map, or CTE settings. These can be inspected in s-center under **IoT → Angle of Arrival**.

### Drivers

- USB CDC class driver — built into Linux kernel; no additional driver needed.
- On Windows, the EVB-ANT-1 may require the FTDI VCP driver if the FTDI option is selected on J2 (see u-blox kit user guide).

---

## XPLR-AOA-3 first-time setup

These steps prepare a fresh kit for use. Skip to the Reproducibility Guide if your kit is already provisioned.

1. **Install s-center classic** from the u-blox website (NINA-B series).
2. **Flash C209 firmware:** remove the battery, connect Micro-USB, hold SW2+RESET to enter DFU mode, then use s-center *Software Update* with `release_for_dfu_boot.zip` from the [u-blox c209-aoa-tag releases](https://github.com/u-blox/c209-aoa-tag/releases).
3. **Configure EVB-ANT-1:** set the J2 jumper to the **F (FTDI)** pins, leave J12 with no jumper, then connect USB-C to PC.
4. **Open s-center** on COM11 (115200 baud, CTS/RTS) → **IoT** → **Angle of Arrival** → enable all checkboxes → **Set**.
5. **Install a CR2032 battery** in the C209 tag.

**Subsequent use:**
- EVB-ANT-1: plug in USB-C, open s-center on COM11 (115200, CTS/RTS), IoT → Angle of Arrival → Resume.
- C209 tag: insert CR2032 battery (or use USB). Tag broadcasts automatically; the tag ID appears in the s-center dropdown within seconds.

---

## Reproducibility guide

### 1. Clone the repository
```bash
git clone https://github.com/Derek-233/EmbWIot_Final_Group5.git
cd EmbWIot_Final_Group5
```

### 2. Install Python dependencies
For exact reproduction (recommended):
```bash
pip3 install -r requirements-lock.txt --break-system-packages
```
Or for direct deps only (faster, allows transitive updates):
```bash
pip3 install -r requirements.txt --break-system-packages
```

### 3. Build the ROS2 packages
```bash
colcon build
source install/setup.bash
```

### 4. Launch the AoA node
```bash
sudo chmod a+rw /dev/ttyUSB2   # adjust port as needed
ros2 launch xplr_aoa3 aoa_launch.py port:=/dev/ttyUSB2
```
The node publishes to `/aoa/measurement` at ~20 Hz.

### 5. Verify live data
```bash
ros2 topic echo /aoa/measurement
```

### 6. Process bag files and convert coordinates
```bash
python3 process_bags.py      # reads bags/, converts az/el to ±180° system
python3 convert_aoa.py       # standalone coordinate conversion utility
```

### 7. Run tag localization
```bash
python3 tag_localization.py              # LOS: points 7-12, error = 10.1 cm
python3 tag_localization_nlos.py         # NLOS: points 13-18, error = 180.6 cm
python3 tag_localization_nlos_no14.py    # NLOS excl. outlier, error = 32.6 cm
```

---

## Troubleshooting

| Symptom | Likely cause / Fix |
|---------|-------------------|
| `/dev/ttyUSB2` not present after plugging in EVB-ANT-1 | Check `dmesg \| tail` for the actual port assignment. Adjust `port:=/dev/ttyUSBx` in the launch command. |
| `Permission denied` on the serial port | Run `sudo chmod a+rw /dev/ttyUSB2`, or add your user to the `dialout` group: `sudo usermod -aG dialout $USER` and re-login. |
| Tag does not appear in s-center dropdown | Confirm CR2032 battery is fresh and seated correctly. Re-flash C209 firmware via DFU mode (see First-Time Setup step 2). |
| `ros2 topic echo /aoa/measurement` shows nothing | Verify the node is running: `ros2 node list` should include `xplr_aoa3_node`. Check the launch terminal for serial connection errors. |
| AoA readings stuck at 0° | Likely NLOS / strong obstruction. Move tag and antenna board to clear line of sight and confirm RSSI > -70 dBm. |
| Localization estimate far from ground truth | Check that all six anchor positions used the same board orientation. Exclude any measurement near the ±90° azimuth boundary (see point14 exclusion below). |

**Offline mode:** the localization pipeline (`process_bags.py` + `tag_localization*.py`) operates entirely on the recorded `bags/` directory and requires no network connectivity. Only the s-center setup step (step 2 of First-Time Setup) requires internet.

---

## Dataset

Bag files are in `bags/`, recorded via the ROS2 node on the Stretch SE3.

| Points | Condition | Tag position | Description |
|--------|-----------|--------------|-------------|
| point1-6 | LOS | Various | Azimuth characterization (bench experiment) |
| point7-12 | LOS | (0, 300) cm | Robot localization, 6 board positions |
| point13-18 | NLOS | (-318, 285) cm | NLOS localization, wall obstruction |

Note: point14 is excluded from NLOS localization due to measurement failure (tag at extreme lateral offset of 4.59 m, near ±90° antenna boundary).