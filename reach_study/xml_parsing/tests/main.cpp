#include "../include/reach_parse/xml_parser.hpp"

#include <iostream>

void testVector(std::string fname, int num) {
    std::vector<PS_RESTRUCTS_H::Restructs::ReachData> poses = ReachXML::XMLParser::parseXML(fname);
    std::cout << poses.capacity() << std::endl << std::endl;

    for (int i = 0; i < num; i++) {
        std::cout << poses[i].result.reachable << std::endl;
        std::cout << poses[i].pose.translation << std::endl;
        std::cout << poses[i].pose.quater << std::endl;
        std::cout << (poses[i].result.reachable? "Sucess! " : "Rip") << std::endl;
        std::cout << poses[i].result.score << std::endl;
    }
}

void testMap(std::string fname, int num) {
    std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> poses = ReachXML::XMLParser::parseMap(fname);
    std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData>::iterator it = poses.begin();
    std::cout <<poses.size() << std::endl << std::endl;

    for (int i = 0; i < num && it != poses.end(); i++) {
        std::cout << it->second.reachable <<std::endl;
        std::cout << it->first.translation <<std::endl;
        std::cout << it->first.quater << std::endl;
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
    testVector("src/point_support/reach_study/reach_support_files/reach.db.xml", numpoints);

    std::cout << "Now testing map mode...\n";
    testMap("src/point_support/reach_study/reach_support_files/reach.db.xml", numpoints);

    return 0;
}