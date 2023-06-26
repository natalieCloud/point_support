#include "../include/reach_parse/xml_parser.hpp"

/**
 * @author Natalie Chmura 
 * 
 * @brief This contains a class that reads information from the XML file genrated by the reach study
 * and parses it into an array of data nodes! (^u^)
 */


namespace ReachXML {

std::vector<XMLParser::PoseData> XMLParser::parseXML(std::string fname) {

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node;
    //Read the file into a vector
    std::ifstream theFile (fname);
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the rapid-xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);
    //Find the root of the data, in our case boost_serialization
    root_node = doc.first_node(0);

    int count = XMLParser::getItemCount(root_node);
    rapidxml::xml_node<> * item_node = XMLParser::descendToItem(root_node);
    std::vector<PoseData> poses = XMLParser::populatePoses(item_node, count);

    return poses;
}

int XMLParser::getItemCount(rapidxml::xml_node<> * root_node) {

    // return (int)(db->results->count->item_version->item->count.value())
    return std::stoi(root_node->first_node()->first_node()->first_node()
        ->next_sibling()->next_sibling()->first_node()->value());
}

rapidxml::xml_node<> * XMLParser::descendToItem(rapidxml::xml_node<> * root_node){

    // return (db->results->count->item_version->item->count->item_version->item)
    return root_node->first_node()->first_node()->first_node()->next_sibling()
        ->next_sibling()->first_node()->next_sibling()->next_sibling();
}

std::vector<XMLParser::PoseData> XMLParser::populatePoses(rapidxml::xml_node<> * item_node, int count) {
    std::vector<XMLParser::PoseData> poseVector;
    poseVector.reserve(count);

    for (int i = 0; i < count && item_node; i++) {
        XMLParser::populateStruct(item_node, &poseVector[i]);
        item_node = item_node->next_sibling();
    }

    return poseVector;
}

void XMLParser::populateStruct(rapidxml::xml_node<> * item_node, struct PoseData *data) {

    data->translation = POINT_SUPPORT_ARRAY_TRANSFORM_H::ReachArray::ArrayTF::getTranslation(XMLParser::getPoseMatrix(item_node));
    data->quater = POINT_SUPPORT_ARRAY_TRANSFORM_H::ReachArray::ArrayTF::getQuaternion(XMLParser::getPoseMatrix(item_node));
    data->reachResult = std::stoi(item_node->first_node()->value());
    data->reachScore = std::atof(item_node->first_node()->next_sibling()->next_sibling()->value());
}

_Float64 * XMLParser::getPoseMatrix(rapidxml::xml_node<> * item_node) {
    
    // item_node = item->reached->goal->matrix->count->item_version->[first]item 
    item_node = item_node->first_node()->next_sibling()->first_node()
        ->first_node()->next_sibling()->next_sibling();

    static _Float64 numMatrix[XMLParser::MATRIX_SIZE];

    for (int i = 0; i < XMLParser::MATRIX_SIZE && item_node; i++) {
        numMatrix[i] = atof(item_node->value());
        item_node = item_node->next_sibling();
    }
    return numMatrix;  
}

} //namespace ReachXML