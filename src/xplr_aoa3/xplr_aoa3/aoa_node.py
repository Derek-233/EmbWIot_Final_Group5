import re
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

import serial

from xplr_aoa3_msgs.msg import AoaMeasurement

UUDF_PATTERN = re.compile(
    r'\+UUDF:([^,]+),(-?\d+),(-?\d+),(-?\d+),(-?\d+),(\d+),'
    r'"([^"]*)","([^"]*)",(\d+),(\d+)'
)


class XplrAoa3Node(Node):

    def __init__(self):
        super().__init__('xplr_aoa3_node')

        self.declare_parameter('port',      '/dev/ttyUSB2')
        self.declare_parameter('baud_rate', 115200)
        self.declare_parameter('frame_id',  'aoa_anchor')

        self.port      = self.get_parameter('port').value
        self.baud_rate = self.get_parameter('baud_rate').value
        self.frame_id  = self.get_parameter('frame_id').value

        qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )
        self.pub = self.create_publisher(AoaMeasurement, 'aoa/measurement', qos)

        self._count = 0
        self.create_timer(10.0, self._log_stats)

        self._running = True
        self._thread  = threading.Thread(target=self._serial_loop, daemon=True)
        self._thread.start()

        self.get_logger().info(
            f'xplr_aoa3_node started  |  port={self.port}  '
            f'baud={self.baud_rate}  frame_id={self.frame_id}'
        )

    def _serial_loop(self):
        while self._running:
            try:
                ser = serial.Serial(self.port, self.baud_rate, timeout=1)
                self.get_logger().info(f'Connected to {self.port}')

                while self._running:
                    try:
                        raw = ser.readline()
                    except Exception as e:
                        self.get_logger().warn(f'Serial read error: {e}')
                        break

                    line = raw.decode('utf-8', errors='ignore').strip()
                    if not line:
                        continue

                    data = self._parse_uudf(line)
                    if data:
                        self._publish(data)

                ser.close()

            except serial.SerialException as e:
                self.get_logger().error(f'Serial error: {e}')
                if 'Permission denied' in str(e):
                    self.get_logger().error(
                        'Fix: sudo usermod -aG dialout $USER  (then re-login)'
                    )
                import time; time.sleep(3.0)

    @staticmethod
    def _parse_uudf(line: str):
        m = UUDF_PATTERN.search(line)
        if not m:
            return None
        return {
            'tag_id':    m.group(1),
            'rssi':      int(m.group(2)),
            'azimuth':   int(m.group(3)),
            'elevation': int(m.group(4)),
            'channel':   int(m.group(6)),
            'anchor_id': m.group(7),
            'timestamp': int(m.group(9)),
            'seq':       int(m.group(10)),
        }

    def _publish(self, data: dict):
        msg = AoaMeasurement()
        msg.header.stamp    = self.get_clock().now().to_msg()
        msg.header.frame_id = self.frame_id
        msg.tag_id    = data['tag_id']
        msg.anchor_id = data['anchor_id']
        msg.azimuth   = data['azimuth']
        msg.elevation = data['elevation']
        msg.rssi      = data['rssi']
        msg.channel   = data['channel']
        msg.timestamp = data['timestamp']
        msg.seq       = data['seq']
        self.pub.publish(msg)
        self._count += 1

    def _log_stats(self):
        self.get_logger().info(f'Published {self._count} measurements total')

    def destroy_node(self):
        self._running = False
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = XplrAoa3Node()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f'Unexpected error: {e}')
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
