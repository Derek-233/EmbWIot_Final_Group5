# EmbWIoT Final Project — Group 5
## BLE AoA-based Indoor Tag Localization on a Stretch Robot Platform

**Team:** Qingyuan Cao, Jonathan Lee, Shyun Lee

**Project Report (PDF):** [EmbWIoT_Project_Group5_20260501.pdf](docs/EmbWIoT_Project_Group5_20260501.pdf)

The report covers the full project progression across weekly check-ins:
- **Slides 2–3:** Motivation — problem background and project contribution
- **Slides 4–5:** Hardware Setup — XPLR-AOA-3 configuration steps and wiring
- **Slides 6–8:** Experimental Setup — LOS/NLOS test methodology and photos
- **Slides 9–13:** AoA Analysis — azimuth and elevation LOS/NLOS comparison charts
- **Slides 14–15:** ROS2 Integration — build and deploy with terminal screenshots
- **Slides 16–20:** Localization Results — method formulas, result tables, and comparison charts
- **Slide 21:** Deliverables — project goals and completion status

---

## Introduction

This project integrates BLE Angle-of-Arrival (AoA) localization using the u-blox XPLR-AOA-3 platform into a WiFi-based robot navigation system running on a Hello Robot Stretch SE3. The goal is to complement existing WiFi sensing with BLE AoA to enable instance-level target identification and localization even when the target is not visually observable.

**Key results:**
- LOS localization error: **10.1 cm** (6 anchor positions)
- NLOS localization error: **32.6 cm** (5 anchor positions, excluding outlier)
- AoA measurement std: **~2.4°** (Az), **~3.6°** (El) under LOS

---

## Hardware

| Component | Model |
|-----------|-------|
| Anchor board | u-blox EVB-ANT-1 with ANT-B10 antenna array |
| BLE tag | u-blox C209 |
| Robot | Hello Robot Stretch SE3 |
| Host | Ubuntu 22.04, connected via USB (ttyUSB) |

**RF specs:** BLE 2.4 GHz, AoA measurement range ±90° azimuth and elevation, ~20 Hz output rate.

---

## Software Environment

- Ubuntu 22.04
- ROS2 Humble
- Python 3.10
- Dependencies:
```bash
pip3 install rosbags numpy scipy
```

---

## Reproducibility Guide

### 1. Clone the repository
```bash
git clone https://github.com/Derek-233/EmbWIot_Final_Group5.git
cd EmbWIot_Final_Group5
```

### 2. Build the ROS2 packages
```bash
cd ~/ros2_iot
colcon build
source install/setup.bash
```

### 3. Launch the AoA node
```bash
sudo chmod a+rw /dev/ttyUSB2
ros2 launch xplr_aoa3 aoa_launch.py port:=/dev/ttyUSB2
```
The node publishes to `/aoa/measurement` at ~20 Hz.

### 4. Process bag files and convert coordinates
```bash
python3 process_bags.py      # Read bag files, convert az/el to ±180° system
python3 convert_aoa.py       # Standalone coordinate conversion utility
```

### 5. Run localization
```bash
python3 tag_localization.py              # LOS: points 7–12
python3 tag_localization_nlos.py         # NLOS: points 13–18
python3 tag_localization_nlos_no14.py    # NLOS excluding outlier point14
```

---

## Dataset

Bag files are in `bags/`, recorded via the ROS2 node on the Stretch robot.

| Points | Condition | Tag position | Description |
|--------|-----------|-------------|-------------|
| point1–6 | LOS | Various | Azimuth characterization |
| point7–12 | LOS | (0, 300) cm | Localization ground truth |
| point13–18 | NLOS | (−318, 285) cm | NLOS localization (human body obstruction) |
