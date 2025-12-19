from setuptools import find_packages
from setuptools import setup

setup(
    name='base_msgs_per',
    version='0.0.0',
    packages=find_packages(
        include=('base_msgs_per', 'base_msgs_per.*')),
)
