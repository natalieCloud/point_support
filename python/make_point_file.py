##@brief A Python file that generates a file full of points that model a square mesh##

import numpy

##
#@mainpage Python TXT Point Generator
#
#@section description_main Description
# A Python file that takes user input and generates a populated
# square mesh of points into a txt file that can be parsed by the
# "TXT to PCD Convertor" program in this module!
#
#@section notes_main Example
# INPUT:
# Enter the name && path of the (.txt) file you wish to generate: *path/to/file/filename.txt*
# Aproximatley how many points would you like in the mesh? (#1^#2 format please):  *3^3*
# What is the center coordinate for your mesh? (x y z format please):  *0 0 0*
# What are the dimensions of the geometry? (#.etc #.etc format please): *2.0 2.0*
# Which surface would you like the geometry to be on? (X OR Y OR Z): *Z*
#
# OUTPUT:
# -1.0 -1.0 0
# -1.0 0 0 0
# -1.0 1.0 0
# 0 -1.0 0
# 0 0 0
# 0 1.0 0
# 1.0 -1.0 0
# 1.0 0 0
# 1.0 1.0 0
##

# FUNCTIONS:
def get_dimensions(usr_nums):

    ##get_dimensions
    #
    # Takes the usr inputted numbers and calculates the length and width points for
    # distribution over a rectangular(?) surface area.
    #
    # @param usr_nums
    # The numbers provided by the user inputted in a list format- they are the:
    # [0] base
    # [1] power
    ##

    dim_nums = [0] * 2

    len_exp = wid_exp = numpy.sqrt(pow(usr_nums[0], usr_nums[1]))

    dim_nums[0] = int(wid_exp)
    dim_nums[1] = int(len_exp)

    return dim_nums

def calc_increments(dimensions, dim_points):

    ##calc_increments
    #
    # Takes the user inputted dimensions of the mesh they wish to generate,
    # as well as the number of points needed across each axis and
    # caculates the aproximate distance between each point!
    #
    # @param dimensions
    # The length (real life equivalent to meters) of the mesh and the
    # width of the mesh stored in a list.
    #
    # @param dim_points
    # The points distributed over the length and width of the geometry
    ##

    inc = [0.0] * 2

    inc[0] = float(dimensions[0] / (dim_points[0] - 1))
    inc[1] = float(dimensions[1] / (dim_points[1] - 1))

    return inc

def calc_start_vertex(old_coor, dimensions, xyz_norm):

    ##calc_start_vertex
    #
    # Caculates the new starting vertex for desired points in space
    #
    # @param old_coor
    # The original coordinates that will be shifted to reflect the
    # desired normalization
    #
    # @param dimensions
    # Dimensions of the piece that will be used to caculate the
    # new coordinate location
    #
    # @param xyz_norm
    # The surface to which the area is normalized
    ##

    new_coor = [0.0] * 3

    if xyz_norm == 0: #Normalized to the YZ plane
        new_coor[0] = old_coor[0]
        new_coor[1] = old_coor[1] - (dimensions[0] / 2)
        new_coor[2] = old_coor[2] - (dimensions[1] / 2)
    elif xyz_norm == 1: #Normalized on the XZ plane
        new_coor[0] = old_coor[0] - (dimensions[0] / 2)
        new_coor[1] = old_coor[1]
        new_coor[2] = old_coor[2] - (dimensions[1] / 2)
    else : #Normalized on the XY plane
        new_coor[0] = old_coor[0] - (dimensions[0] / 2)
        new_coor[1] = old_coor[1] - (dimensions[1] / 2)
        new_coor[2] = old_coor[2]

    return new_coor

def print_file(output, num_points, dimensions, coordinates, xyz_norm):

    ##print_file
    #
    # Takes all of the user-inputted information and caculates the
    # distribution of the points over the desired surface area.
    # This surface area is cenetered at a point in space relative to
    # the origin that the user specifies!
    #
    # @param output
    # The wiriter that writes to the desired output file!
    #
    # @param num_points
    # The number of points that will be distributed along each edge!
    #
    # @param dimensions
    # The dimensions of the piece that the user desires
    #
    # @param coordinates
    # The ceneter coordinates of the piece relative to the origin
    #
    # @param  xyz_norm
    # Which coordinate plane the surface of the points should be 
    # normalized to
    ## num_points

    dim_nums = get_dimensions(num_points)

    increments = calc_increments(dimensions, dim_nums)

    coordinates = calc_start_vertex(coordinates, dimensions, xyz_norm)

    for i in range(0, dim_nums[0]):
        for j in range(0, dim_nums[1]):
            if xyz_norm == 0:
                output.write(str(coordinates[0]) + " " + str((coordinates[1] + (j * increments[0]))) + " " + str((coordinates[2] + (i * increments[1]))) + "\n")
            elif xyz_norm == 1:
                output.write(str((coordinates[0] + (j * increments[0])))+ " " + str(coordinates[1]) + " " + str((coordinates[2] + (i * increments[1]))) + "\n")
            else:
                output.write(str((coordinates[0] + (j * increments[0]))) + " " + str((coordinates[1] + (i * increments[1]))) + " " + str(coordinates[2]) + "\n")
            



# MAIN:

# Looking to be a bit of a monolithic main like our good friend in txt_to_pcd.py- will be refactored!
def main():
    out_file_name = input("Enter the name && path of the (.txt) file you wish to generate: ")
    out_file = open(out_file_name, "w")

    usr_num_points = input("Aproximatley how many points would you like in the mesh? (#1^#2 format please): ")

    num_points = [int(x) for x in usr_num_points.split("^")]

    # TODO: Maybe see about specifying distribution of points? Or maybe applying based on
    # selected dimensions.

    usr_start_coor = input("What is the center coordinate for your mesh? (x y z format please): ")
    coordinates = [float(x) for x in usr_start_coor.split()]

    usr_wid_len = input("What are the dimensions of the geometry? (#.etc #.etc format please): ")
    dimensions = [float(x) for x in usr_wid_len.split()]
    #dimensions += [1.0, 1.0]

    print()
    print(" x     z      ")
    print("  \  Y ^      ")
    print(" Z  \  |  X   ")
    print("      \|      ")
    print(" y<----|----> ")
    print("       |\     ")
    print("       |  \   ")
    print("       |    \ ")
    print()
    usr_xyz = input("Which surface would you like the geometry to be on? (X OR Y OR Z): ")

    xyz_norm = 2
    if usr_xyz == 'X':
        xyz_norm = 0
    elif usr_xyz == 'Y':
        xyz_norm = 1


    # TODO: Include different shapes? Like circular maybe? That would require different forms of
    # splitting up the number of points and getting the evenly distributed over theat the point in space relative to the origin that the user desires
    # TODO: Maybe convert this file to C++ or another language? Python isn't exactly optimized for 
    # for loops................................................................... :/

    print_file(out_file, num_points, dimensions, coordinates, xyz_norm)

    out_file.close()


if __name__ == "__main__":
    main()
