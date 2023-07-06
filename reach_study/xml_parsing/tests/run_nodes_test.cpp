#include "../include/reach_parse/result_parsing.hpp"
#include "../include/reach_parse/xml_parser.hpp"

//#include <ros/ros.h>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/header.h>
#include <geometry_msgs/msg/pose.h>
#include <geometry_msgs/msg/pose_array.h>


#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <string>

////////////////
// MAIN CLASS //
////////////////

/** 
 * ResultNode
*/
class ResultNode : public rclcpp::Node
{
public:
    ResultNode()
    : Node("result_node")
    {


    geometry_msgs::msg::PoseArray ps;
    //geometry_msgs::msg::PoseArray * psPtr = &ps;
    // poses.reserve(1);
    ps.header.frame_id = std::string("world");
    ps.header.stamp = this->get_clock()->now();

    geometry_msgs::msg::Pose pose1;

    pose1.position.x = 1.79747748374938965e+00;
    pose1.position.y = 5.34999966621398926e-01;
    pose1.position.z = 8.26009094715118408e-01;
    pose1.orientation.x = -0.05422189674604809;
    pose1.orientation.y = -0.02781906588900431;
    pose1.orientation.z = -0.7079548626402165;
    pose1.orientation.w = 0.7036234774013702;

    ps.poses.push_back(pose1);

    std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> poseMap = POINT_SUPPORT_XML_PARSER_H::ReachXML::XMLParser::parseMap("src/point_support/reach_study/reach_support_files/reach.db.xml");
    std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData>::iterator it = poseMap.begin();

    PS_RESTRUCTS_H::Restructs::PoseData p1;
    p1.translation.x() = 1.79747748374938965e+00;
    p1.translation.y() = 5.34999966621398926e-01;
    p1.translation.z() = 8.26009094715118408e-01;
    p1.quater.x() = -0.05422189674604809;
    p1.quater.y() = -0.02781906588900431;
    p1.quater.z() = -0.7079548626402165;
    p1.quater.w() = 0.7036234774013702;

    std::cout << "Score: " << poseMap[p1].score << std::endl;
    
    // for( auto i = poseMap.begin(); i != poseMap.end(); i++) {
    //     std::cout << i->first.translation << std::endl;
    //     std::cout << i->second.score <<std::endl;
    // }

    std::vector<_Float64> vec = PS_RESULT_THREADING_H::Scorter::Retriever::getScoreData(ps, poseMap, 1);
    std::cout << "Does it work?  " << vec[0] << std::endl;

    }




}; //ResulNode



int main (int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ResultNode>());
    rclcpp::shutdown();
    return 0;
}











///////////////////// OLD ////////////////////////



// int main (int argv, char **argc) {

//     std::cout << "It Executes!!!" << std::endl;

//     // std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> poseMap = POINT_SUPPORT_XML_PARSER_H::ReachXML::XMLParser::parseMap("src/point_support/reach_study/reach_support_files/reach.db.xml");

//     // std::vector<_Float64> vec = PS_RESULT_THREADING_H::Scorter::Retriever::getScoreData(ps, poseMap, 1);

//     // std::cout << vec[0] << std::endl;

//     return 0;
// }