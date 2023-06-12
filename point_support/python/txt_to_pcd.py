##@brief A Python file that processes .txt data into a .pcd format ##

##
# @mainpage Python TXT To PCD Convertor
#
# @section description_main Description
# A Python file that processes .txt files genarated by the current "path-planning"
# algorithm into a pcd format that is able to be processed in the SWRI Reach module!
#
# @section notes_main Example
# INPUT:
# 7.6918 5.8782 1.8389
# 5.5458 2.5984 3.68
#
# OUTPUT:
# # .PCD v0.7 - Point Cloud Data file format
# VERSION 0.7
# FIELDS x y z normal_x normal_y normal_z curvature
# SIZE 4 4 4 4 4 4 4
# TYPE F F F F F F F
# COUNT 1 1 1 1 1 1 1
# WIDTH 2 //The number of rows of the original file
# HEIGHT 1he
# VIEWPOINT 0 0 0 1 0 0 0
# POINTS 2 //Same as the width above
# DATA ascii
# 7.6918 5.8782 1.8389 0 0 1 0
# 5.5458 2.5984 3.68 0 0 1 0
##

# FUNCTIONS:

def process_file(inFile):

    ##process_file
    #
    # Takes in the data from .txt file and parses it into an array of lists of floats
    # This will allow us to perform operations on all of the floats later if needed to
    # transform the data points later!
    #
    # @param inFile
    # The file that tnhat data is read from.
    ##

    data = []
    for line in inFile:
        line.strip('\n')
        floats = [float(x) for x in line.split()]
        data.append(floats)

    return data

def write_file(outFile, data, rpyc):

    ##write_file
    #
    # Writes the data from the array of lists to the output file!
    #
    # @param outFile
    # The printer that writes to the output file!
    #
    # @param data
    # The 2D list o' lists that contains each of the data points in a float format.
    #
    # @param rpyc
    # The roll, pitch, yaw and curvature that will be applied to each point!
    ##

    vertex_num = len(data)

    outFile.write("# .PCD v0.7 - Point Cloud Data file format\n")
    outFile.write("VERSION 0.7\nFIELDS x y z normal_x normal_y normal_z curvature\n")
    outFile.write("SIZE 4 4 4 4 4 4 4\nTYPE F F F F F F F\nCOUNT 1 1 1 1 1 1 1\n")
    outFile.write("WIDTH " + str(vertex_num) + "\nHEIGHT 1\nVIEWPOINT 0 0 0 1 0 0 0\n")
    outFile.write("POINTS " + str(vertex_num) + "\nDATA ascii\n")

    for line in data:
        for x in line:
            outFile.write(str(x) + " ")
        outFile.write(str(rpyc[0]) + " " + str(rpyc[1]) + " " + str(rpyc[2]) + " " + str(rpyc[3]) + "\n" )

def transform_data(data, x_transf, y_transf, z_transf):

    ##transform_data
    #
    # Applies user inputted transformations to allow for the translation
    # of the desired mesh in ralation to the kinematic base frame of the
    # model!
    #
    # @param data
    # The 2D list o' lists that contains each of the data points in a float format.
    #
    # @param x_transf
    # The transformation to be applied to the x direction for the point specified.
    #
    # @param y_transf
    # The transformation to be applied to the y direction for the point specified.
    #
    # @param z_transf
    # The transformation to be applied to the z direction for the point specified.
    ##

    for line in data:
        line[0] += x_transf
        line[1] += y_transf
        line[2] += z_transf

def squash_data(data, x_squash, y_squash, z_squash):
    
    ##squash_data
    #
    # Squashes the user input data do be like.... squahed. This is an aesthetic
    # decision that I made for certain sets of points- it may prove nessesary
    # beyond the initial use though so in it stays!
    #
    # @param data
    # The 2D list o' lists that contains each of the data points in a float format.
    #
    # @param x_squash
    # The squash factor to be applied to the x direction for the point specified.
    #
    # @param y_squash
    # The squash factor to be applied to the y direction for the point specified.
    #
    # @param z_squash
    # The squash factor to be applied to the z direction for the point specified.
    ##

    for line in data:
        line[0] *= x_squash
        line[1] *= y_squash
        line[2] *= z_squash

# MAIN:

# A bit of a monolithic main rn :( will work on cleaning it up.
def main():

    in_file_name = input("Enter the (.txt) file name && path you wish to read from: ")
    out_file_name = input("Enter the name of the (.pcd) file name && path that you wish to write to: ")

    in_file = open(in_file_name, "r")
    out_file = open(out_file_name, "w")

    data = process_file(in_file)

    call_t_s = input("Do you wish to squash the file data? Y/N: ")
    if ('Y' == call_t_s):
        print("Enter the squash factor that you wish to apply to each point (X, Y, and Z)")
        x_squash = float(input("X squash: "))
        y_squash = float(input("Y squash: "))
        z_squash = float(input("Z squash: "))
        squash_data(data, x_squash, y_squash, z_squash)

    call_t_d = input("Do you wish to transform the file data? Y/N: ")
    if ('Y' == call_t_d):
        print("Enter the coordinates for each transformation (Right-Hand Cartesian Coordinates)")
        x_transf = float(input("X transformation: "))
        y_transf = float(input("Y transformation: "))
        z_transf = float(input("Z transformation: "))
        transform_data(data, x_transf, y_transf, z_transf)

    call_rpy = input("Do you wish to use the default RPY and curvature for each point? (0 0 0 0) Y/N: ")
    rpyc = [0, 0, 0, 0]
    if ('N' == call_rpy):
        print("Enter the rpy and curvature that you'd like to be applied to the data: ")
        rpyc[0] = float(input("Roll: "))
        rpyc[1] = float(input("Pitch: "))
        rpyc[2] = float(input("Yaw: "))
        rpyc[3] = float(input("Curvature: "))

    write_file (out_file, data, rpyc)

    in_file.close()
    out_file.close()

if __name__ == "__main__":
    main()
