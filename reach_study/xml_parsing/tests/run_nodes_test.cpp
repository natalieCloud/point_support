//#include "../include/reach_parse/result_parsing.hpp"
#include "../include/reach_parse/xml_parser.hpp"

//#include <rclcpp/rclcpp.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <string>

int main (int argv, char **argc) {

    std::cout << "It Executes!!!" << std::endl;

    std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> poseMap = POINT_SUPPORT_XML_PARSER_H::ReachXML::XMLParser::parseMap("../../reach_support_files/reach.db.xml");

    return 0;
}