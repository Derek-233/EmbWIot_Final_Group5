from rosbags.rosbag2 import Reader
from rosbags.typesys import Stores, get_typestore, get_types_from_msg
from pathlib import Path
import numpy as np

BASE = Path(__file__).parent
MSG_PATH = BASE / 'src/xplr_aoa3_msgs/msg/AoaMeasurement.msg'
BAGS_DIR = BASE / 'bags'

typestore = get_typestore(Stores.ROS2_HUMBLE)
msg_text = MSG_PATH.read_text()
custom_types = get_types_from_msg(msg_text, 'xplr_aoa3_msgs/msg/AoaMeasurement')
typestore.register(custom_types)

def convert_aoa(az_deg, el_deg):
    az = np.radians(az_deg)
    el = np.radians(el_deg)
    vx = np.sin(az) * np.cos(el)
    vy = np.cos(az) * np.cos(el)
    vz = np.sin(el)
    az_new = np.degrees(np.arctan2(vx, vz))
    el_new = np.degrees(np.arctan2(vy, np.sqrt(vx**2 + vz**2)))
    return az_new, el_new

EXCLUDE = {14}

print(f"{'Point':<8} {'Samples':>7} {'Az_orig':>9} {'El_orig':>9} | {'Az_new':>9} {'El_new':>9}")
print('-' * 60)

for i in range(7, 19):
    if i in EXCLUDE:
        print(f"point{i:<4} {'(excluded)':>7}")
        continue

    bag_path = BAGS_DIR / f'point{i}'
    if not bag_path.exists():
        print(f"point{i}: not found")
        continue

    az_list, el_list, az_new_list, el_new_list = [], [], [], []

    with Reader(str(bag_path)) as reader:
        for connection, timestamp, rawdata in reader.messages():
            if connection.topic == '/aoa/measurement':
                msg = typestore.deserialize_cdr(rawdata, connection.msgtype)
                az_n, el_n = convert_aoa(msg.azimuth, msg.elevation)
                az_list.append(msg.azimuth)
                el_list.append(msg.elevation)
                az_new_list.append(az_n)
                el_new_list.append(el_n)

    if az_list:
        print(f"point{i:<4} {len(az_list):>7} "
              f"{np.mean(az_list):>8.2f}° {np.mean(el_list):>8.2f}° | "
              f"{np.mean(az_new_list):>8.2f}° {np.mean(el_new_list):>8.2f}°")
