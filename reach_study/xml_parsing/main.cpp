#include "xml_parser.hpp"

#include <iostream>

/**
 * Used in manual testing, the actual func written above does the brunt of it 
 * (and should be able to be called elsewhere)
*/
int main(int argc, char **argv) { 

    std::vector<ReachXML::XMLParser::PoseData> poses = ReachXML::XMLParser::parseXML(argv[1]);

    std::cout << (poses[0].reachResult) << std::endl;
    std::cout << (poses[0].translation) << std::endl;
    std::cout << (poses[0].quater) << std::endl;
    std::cout << (poses[0].reachResult? "Sucess!" : "Rip") << std::endl;

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