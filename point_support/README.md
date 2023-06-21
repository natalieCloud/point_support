# point_support README

This repository contains various programs that aided in the testing of the limits of ROS-Industrial's [Reach Package](https://github.com/ros-industrial/reach_ros2) 
The goal was to enable creation of various (as of now- see python comments for details) rectangular point cloud files to both test reachability for a local robot (Motoman gp20) as well as testing the limits
of how many points RVIZ could be given and reach scores assed before we would start running into issues- as of 6/8/23 the max cap* was deemed to be 1000

*There can be more- theoretically- however when increased by a factor of 10 the program began to have issues- see /testing/upper_bounds.txt for details!

# *Python Code*

## make_point_file.py
A Python file that takes user input and generates a populated rectangular mesh of points into a txt file that is the apporopriate format to be parsed by the "TXT to PCD converter" in this repo!

**SAMPLE INPUT:**
> Enter the name && path of the (.txt) file you wish to generate: *path/to/file/filename.txt*<br>
> Aproximatley how many points would you like in the mesh? (#1^#2 format please):  *3^3*<br>
> What is the center coordinate for your mesh? (x y z format please):  *0 0 0*<br>
> What are the dimensions of the geometry? (#.etc #.etc format please): *2.0 2.0*<br>
> Which surface would you like the geometry to be on? (X OR Y OR Z): *Z*<br>

**SAMPLE OUTPUT:**
> *filename.txt*<br>
> -1.0 -1.0 0<br>
> -1.0 0 0<br>
> -1.0 1.0 0<br>
> 0 -1.0 0<br>
> 0 0 0<br>
> 0 1.0 0<br>
> 1.0 -1.0 0<br>
> 1.0 0 0<br>
> 1.0 1.0 0 <br>

## txt_to_pcd.py
A Python file that processes .txt files generated by the current "path-planning" algorithm into a pcd (v0.7) format that is able to be processed by the ROS-Industrial reach_ros2 package!

**SAMPLE INPUT:**
> *sample_imput.txt*<br>
> 7.6918 5.8782 1.8389<br>
> 5.5458 2.5984 3.68<br>
><br>
> Enter the (.txt) file name && path you wish to read from: *path/to/file/sample_input.txt*<br>
> Enter the name of the (.pcd) file name && path that you wish to write to: *path/to/file/sample_ouput.pcd*<br>
> Do you wish to squash the file data? Y/N: *N*<br>
> Do you wish to transform the file data? Y/N: *N*<br>
> Do you wish to use the default RPY and curvature for each point? (0 0 0 0) Y/N: *Y*<br>

**SAMPLE OUTPUT:**
> *sample_ouput.pcd*<br>
> #.PCD v0.7 - Point Cloud Data file format<br>
> VERSION 0.7<br>
> FIELDS x y z normal_x normal_y normal_z curvature<br>
> SIZE 4 4 4 4 4 4 4<br>
> TYPE F F F F F F F<br>
> COUNT 1 1 1 1 1 1 1<br>
> WIDTH 2 //The number of rows of the original file<br>
> HEIGHT 1<br>
> VIEWPOINT 0 0 0 1 0 0 0<br>
> POINTS 2 //Same as the width above<br>
> DATA ascii<br>
> 7.6918 5.8782 1.8389 0 0 0 0<br>
> 5.5458 2.5984 3.68 0 0 0 0<br>