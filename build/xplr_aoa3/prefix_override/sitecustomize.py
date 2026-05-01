import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/qingyuan/ros2_iot/install/xplr_aoa3'
