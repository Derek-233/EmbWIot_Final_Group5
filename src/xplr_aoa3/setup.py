from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'xplr_aoa3'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.py')),
    ],
    install_requires=['setuptools', 'pyserial'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='ROS 2 driver for u-blox XPLR-AOA-3 BLE AoA kit',
    license='MIT',
    entry_points={
        'console_scripts': [
            'aoa_node = xplr_aoa3.aoa_node:main',
        ],
    },
)
