#include "../include/reach_parse/xml_parser.hpp"

#include <iostream>

/**
 * Used in manual testing, the actual func written above does the brunt of it 
 * (and should be able to be called elsewhere)
*/
int main(int argc, char **argv) { 

    std::vector<ReachXML::XMLParser::PoseData> poses = ReachXML::XMLParser::parseXML(argv[1]);

    int numpoints = 0;

    std::cout << "How many points would you like printed? \n";
    std::cin >> numpoints;

    for (int i = 0; i < numpoints; i++) {
    std::cout << (poses[i].reachResult) << std::endl;
    std::cout << (poses[i].translation) << std::endl;
    std::cout << (poses[i].quater) << std::endl;
    std::cout << (poses[i].reachResult? "Sucess!" : "Rip") << std::endl;
    }

    return 0;
}
    //TEST PRINT START
    // int count = xmlParser::getItemCount(root_node);
    // rapidxml::xml_node<> * item_node = xmlParser::descendToItem(root_node);
    // struct poseData test;
    // xmlParser::populateStruct(item_node, &test);
    // std::cout.precision(17);
    // std::cout  << test.reachScore << std::endl;
    // struct poseData poses[count];
    // xmlParser::populatePoses(item_node, poses, count);

    // std::cout << "Number of nodes: " << count << std::endl;
    // std::cout << "First node reached? " << poses[0].reachResult << std::endl;
    // std::cout << "Reach Score? " << poses[0].reachScore << std::endl;
    //TEST PRINT END