from setuptools import find_packages
from setuptools import setup

setup(
    name='xplr_aoa3_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('xplr_aoa3_msgs', 'xplr_aoa3_msgs.*')),
)
