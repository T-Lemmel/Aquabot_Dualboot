from setuptools import find_packages
from setuptools import setup

setup(
    name='move_ekf',
    version='1.0.0',
    packages=find_packages(
        include=('move_ekf', 'move_ekf.*')),
)
