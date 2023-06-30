#include "../include/reach_parse/xml_parser.hpp"

#include <iostream>

void testVector(std::string fname, int num) {
    std::vector<PS_RESTRUCTS_H::Restructs::ReachData> poses = ReachXML::XMLParser::parseXML(fname);
    std::cout << poses.capacity() << std::endl << std::endl;

    for (int i = 0; i < num; i++) {
        std::cout << poses[i].result.reachable << std::endl;
        std::cout << poses[i].newPose.position.x << std::endl;
        std::cout << poses[i].newPose.orientation.w << std::endl;
        std::cout << (poses[i].result.reachable? "Sucess! " : "Rip") << std::endl;
        std::cout << poses[i].result.score << std::endl;
    }
}

void testMap(std::string fname, int num) {
    std::map<geometry_msgs::msg::Pose, PS_RESTRUCTS_H::Restructs::ResultData> poses = ReachXML::XMLParser::parseMap(fname);
    std::map<geometry_msgs::msg::Pose, PS_RESTRUCTS_H::Restructs::ResultData>::iterator it = poses.begin();
    std::cout <<poses.size() << std::endl << std::endl;

    for (int i = 0; i < num && it != poses.end(); i++) {
        std::cout << it->second.reachable <<std::endl;
        std::cout << it->first.position.x <<std::endl;
        std::cout << it->first.orientation.w << std::endl;
        std::cout << (it->second.reachable? "Sucess!" : "Rip") << std::endl;
        std::cout << it->second.score <<std::endl;
    }
}

/**
 * Used in manual testing, the actual func written above does the brunt of it 
 * (and should be able to be called elsewhere)
*/
int main(int argc, char **argv) { 

    int numpoints = 0;
    std::cout << "How many points would you like printed? \n";
    std::cin >> numpoints;

    std::cout << "Now testing vector mode...\n";
    testVector(argv[1], numpoints);

    std::cout << "Now testing map mode...\n";
    testMap(argv[1], numpoints);

    return 0;
}