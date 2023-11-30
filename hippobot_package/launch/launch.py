from simple_launch import SimpleLauncher
import os

sl = SimpleLauncher(use_sim_time=True)
base_path = os.path.abspath(os.path.dirname(__file__))

def launch_setup():

    sl.node('hippobot_package', 'cloud_reader')
    sl.node('hippobot_package', 'obstacle_node.py')
    sl.node('hippobot_package', 'map_node.py')

    return sl.launch_description()


generate_launch_description = sl.launch_description(launch_setup)
