#include "../include/reach_parse/result_parsing.hpp"
#include "../include/reach_parse/xml_parser.hpp"

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_array.hpp>

#include <stdlib.h>
#include <stdio.h>

#include <string>

int main (int argv, char **argc) {

    std::cout << "It Executes!!!" << std::endl;

    std::map<geometry_msgs::msg::Pose, PS_RESTRUCTS_H::Restructs::ResultData> poseMap = POINT_SUPPORT_XML_PARSER_H::ReachXML::XMLParser::parseMap("../../reach_support_files/reach.db.xml");

    return 0;
}