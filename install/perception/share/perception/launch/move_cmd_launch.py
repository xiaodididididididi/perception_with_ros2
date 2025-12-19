from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    car_move_cmd = Node(
        package="perception",
        executable="car_move_cmd",
        name="car_move_cmd",
    )

    obs_move_cmd = Node(
        package="perception",
        executable="obs_move_cmd",
        name="obs_move_cmd",
    )

    return LaunchDescription([car_move_cmd, obs_move_cmd])
