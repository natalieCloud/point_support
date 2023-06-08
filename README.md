# point_support

This repository contains various programs that aided in the testing of the limits of ROS-Industrial's [Reach Package](https://github.com/ros-industrial/reach_ros2) 
The goal was to enable creation of various (as of now- see python comments for details) rectangular point cloud files to both test reachability for a local robot (Motoman gp20) as well as testing the limits
of how many points RVIZ could be given and reach scores assed before we would start running into issues- as of 6/8/23 the max cap* was deemed to be 1000

## Python Code
### make_point_file.py
A Python file that takes user input and generates a populated rectangular mesh of points into a txt file that is the apporopriate format to be parsed by the "TXT to PCD converter" in this repo!


*There can be more- throretically- however when increased by a factor of 10 the program began to have issues- see /testing/upper_bounds.txt for details!
