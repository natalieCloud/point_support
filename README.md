# reach_support_files README

This repository contains various programs that aided in the testing and expansion of the limits of ROS-Industrial's [Reach Package](https://github.com/ros-industrial/reach_ros2) 
The goal was to create various programs that would aid in the linkage between the reach package and a ros2 based path planner to integrate the reach scores for the path back into our path plan!

As of now this package contains the [**point_support**](https://github.com/natalieCloud/reach_support_files/tree/main/point_support) and [**reach_study**](https://github.com/natalieCloud/reach_support_files/tree/main/reach_study) packages. 

The **point_support** package allows conversion of user input to a text file, and then a (either user created or inner package created) txt file into a pcd mesh file! This can allow for easy ``Gridset`` .pcd generation! It also allows for conversion of a ``geometry_msgs PoseArray`` into the final pcd formatting as well- condusive to our main goal! (Rather than the extension as mentioned before)

The **reach_study** package contains the msg files that allow the linkage of a ``PoseArray`` to its associated reachability scores as returned after the reach score has been conducted on those points! 

:3 
