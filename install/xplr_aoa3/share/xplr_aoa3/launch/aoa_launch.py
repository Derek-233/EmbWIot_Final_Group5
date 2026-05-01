from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([

        DeclareLaunchArgument(
            'port',
            default_value='/dev/ttyUSB2',
            description='Serial port of the XPLR-AOA-3 anchor board'
        ),
        DeclareLaunchArgument(
            'baud_rate',
            default_value='115200',
            description='Serial baud rate'
        ),
        DeclareLaunchArgument(
            'frame_id',
            default_value='aoa_anchor',
            description='TF frame ID published in message headers'
        ),

        Node(
            package='xplr_aoa3',
            executable='aoa_node',
            name='xplr_aoa3_node',
            output='screen',
            parameters=[{
                'port':      LaunchConfiguration('port'),
                'baud_rate': LaunchConfiguration('baud_rate'),
                'frame_id':  LaunchConfiguration('frame_id'),
            }],
        ),
    ])
