#include "../include/result_processing/distance_claculator.hpp"

/**
 * @author Natalie Chmura
 * 
 * @brief A class that calculates the distance between two points orientation in a 3D plane!
 */

/**
 * @namespace SpaceSpan
 */
namespace SpaceSpan {

Distance::DistData Distance::findDistance(ReachXML::XMLParser::PoseData pose1, ReachXML::XMLParser::PoseData pose2) {
}

_Float64 Distance::distTranslation(Eigen::Vector3d point1, Eigen::Vector3d point2) {
    return (sqrt(
        pow((point1(0) - point2(0)), 2) + 
        pow((point1(1) - point2(1)), 2) + 
        pow((point1(2) - point2(2)), 2)));
}

Eigen::Quaternion<_Float64> Distance::distRotation(Eigen::Quaternion<_Float64> quat1, Eigen::Quaternion<_Float64> quat2) {
    return quat1 * quat2.inverse();
}

} //namespace SpaceSpan