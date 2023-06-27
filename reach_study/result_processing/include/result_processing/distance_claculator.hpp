#ifndef POINT_SUPPORT_DISTANCE_CALCULATOR_H
#define POINT_SUPPORT_DISTANCE_CALCULATOR_H

#include <eigen3/Eigen/Geometry>
#include <math.h>

#include "../../../xml_parsing/include/reach_parse/xml_parser.hpp"

/**
 * @author Natalie Chmura
 * 
 * @brief A class that calculates the distance between two points orientation in a 3D plane!
 */

/**
 * @namespace SpaceSpan
 */
namespace SpaceSpan {

/**
 * @class Distance
 * 
 * @brief This class takes the position and orientation of two points in a 3D plane and caculates
 * the distance between the two, (or via singular comparisions)
 */
class Distance {
    public:

        /**
         * @struct DistData
         * @brief Struct that contains distance data
         * 
         * @param distance A float that records the distance between two xyz coordinates
         * @param rotation The distance between two rotations (Stored as quaternions)
         */
        struct DistData {
            _Float64 ditance;
            Eigen::Quaternion<_Float64> rotation;
        };

        /**
         * @brief This function inputs the position and orientation of two points in space
         * and returns the distance between them in the form of distance and rotation
         * 
         * @param pose1: The first pose in space, contains translation and rotation
         * @param pose2: The second pose in space, contains translation and rotation
         * 
         * @returns
         * A struct containing the distance data, for both translation and rotation
         */
        static DistData findDistance(ReachXML::XMLParser::PoseData pose1, 
            ReachXML::XMLParser::PoseData pose2);
        
        /**
         * @brief This function takes two points in a 3D plane (xyz coordinate system)
         * and finds the distance between the two
         * 
         * @param point1: The first point in space
         * @param point2: the second vector in space 
         * 
         * @returns
         * The distance between the two points
         */
        static _Float64 distTranslation(Eigen::Vector3d point1, Eigen::Vector3d point2);

        /**
         * @brief This function takes two points in a 3D plane and calculates the rotational
         * distance between them.
         * 
         * @param quat1: The first quaternion orientation
         * @param quat2: The second quaternion orientation
         * 
         * @returns
         * The rotational ditance between point 1 to point 2
         */
        static Eigen::Quaternion<_Float64> distRotation(Eigen::Quaternion<_Float64> quat1,
            Eigen::Quaternion<_Float64> quat2);

};

} //namespace SpaceSpan


#endif //POINT_SUPPORT_DISTANCE_CALCULATOR_H