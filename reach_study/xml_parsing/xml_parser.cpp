#include "xml_parser.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fstream>

#include <vector>
#include <string>

namespace reachXML {

std::vector<xmlParser::PoseData> xmlParser::parseXML(std::string fname) {

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node;
    //Read the file into a vector
    std::ifstream theFile (fname);
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the rapid-xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);
    //Find the root of the data, in our case, boost_serialization
    root_node = doc.first_node(0);

    int count = xmlParser::getItemCount(root_node);
    rapidxml::xml_node<> * item_node = xmlParser::descendToItem(root_node);
    //Reads the poses into a vector
    std::vector<PoseData> poses = xmlParser::populatePoses(item_node, count);

    return poses;
}

int xmlParser::getItemCount(rapidxml::xml_node<> * root_node) {

    // return (int)(db->results->count->item_version->item->count.value())
    return std::stoi(root_node->first_node()->first_node()->first_node()
        ->next_sibling()->next_sibling()->first_node()->value());
}

rapidxml::xml_node<> * xmlParser::descendToItem(rapidxml::xml_node<> * root_node){

    // return (db->results->count->item_version->item->count->item_version->item)
    return root_node->first_node()->first_node()->first_node()->next_sibling()
        ->next_sibling()->first_node()->next_sibling()->next_sibling();
}

std::vector<xmlParser::PoseData> xmlParser::populatePoses(rapidxml::xml_node<> * item_node, int count) {
    std::vector<xmlParser::PoseData> poseVector;
    poseVector.reserve(count);

    for (int i = 0; i < count && item_node; i++) {
        xmlParser::populateStruct(item_node, &poseVector[i]);
        item_node = item_node->next_sibling();
    }

    return poseVector;
}

void xmlParser::populateStruct(rapidxml::xml_node<> * item_node, struct PoseData *data) {

    data->pose = xmlParser::getPoseMatrix(item_node);
    data->reachResult = std::stoi(item_node->first_node()->value());
    data->reachScore = std::atof(item_node->first_node()->next_sibling()->next_sibling()->value());
}

_Float64 * xmlParser::getPoseMatrix(rapidxml::xml_node<> * item_node) {
    
    // item_node = item->reached->goal->matrix->count->item_version->[first]item 
    item_node = item_node->first_node()->next_sibling()->first_node()
        ->first_node()->next_sibling()->next_sibling();

    static _Float64 numMatrix[xmlParser::MATRIX_SIZE];

    for (int i = 0; i < xmlParser::MATRIX_SIZE && item_node; i++) {
        numMatrix[i] = atof(item_node->value());
        item_node = item_node->next_sibling();
    }
    return numMatrix;  
}

} //namespace reachXML