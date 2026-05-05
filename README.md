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

## Hardware

| Component | Model / Details |
|-----------|----------------|
| Anchor board | u-blox EVB-ANT-1 with ANT-B10 8-element patch antenna array |
| BLE module | NINA-B411 (on EVB-ANT-1) |
| BLE tag | u-blox C209, CR2032 battery |
| Robot | Hello Robot Stretch SE3 |
| Host (bench) | Windows PC, COM11, 115200 baud, CTS/RTS |
| Host (robot) | Ubuntu 22.04 on Stretch, `/dev/ttyUSB2` |

**RF specs:** BLE 2.4 GHz, AoA range ±90° azimuth and elevation, ~20 Hz output rate.

---

## Software Environment

- Ubuntu 22.04 / ROS2 Humble
- Python 3.10
- Dependencies (see `requirements.txt`):
```bash
pip3 install -r requirements.txt --break-system-packages
```

---

## XPLR-AOA-3 First-Time Setup

These steps prepare a fresh kit for use. Skip to the Reproducibility Guide if your kit is already provisioned.

1. **Install s-center classic** from the u-blox website (NINA-B series).
2. **Flash C209 firmware:** remove the battery, connect Micro-USB, hold SW2+RESET to enter DFU mode, then use s-center *Software Update* with `release_for_dfu_boot.zip` from the u-blox GitHub.
3. **Configure EVB-ANT-1:** set the J2 jumper to the **F (FTDI)** pins, leave J12 with no jumper, then connect USB-C to PC.
4. **Open s-center** on COM11 (115200 baud, CTS/RTS) → **IoT** → **Angle of Arrival** → enable all checkboxes → **Set**.
5. **Install a CR2032 battery** in the C209 tag.

**Subsequent use:**
- EVB-ANT-1: plug in USB-C, open s-center on COM11 (115200, CTS/RTS), IoT → Angle of Arrival → Resume.
- C209 tag: insert CR2032 battery (or use USB). Tag broadcasts automatically; the tag ID appears in the s-center dropdown within seconds.

---

## Reproducibility Guide

### 1. Clone the repository
```bash
git clone https://github.com/Derek-233/EmbWIot_Final_Group5.git
cd EmbWIot_Final_Group5
```

### 2. Install Python dependencies
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