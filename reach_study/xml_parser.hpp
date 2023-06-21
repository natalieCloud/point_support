#include <string>
#include "../rapidxml.hpp"

//TODO: Change above- try reinstalling the rapidxml package since currrently the includes of the local package is not working.
//Figure out a way for the rapidxml.hpp to be pulled into whatever program uses this parsing code

// Defines the struct
struct poseData {
    _Float64 pose [16]; //The Isometry3D representation of the pose
    int reachResult; //Whether or not the pose is considered "reachable"
    _Float64 reachScore; //The score for the reachability of a certain point
};

/*
* Takes in an xml file and returns a list of poses
*/
void parseXML(std::string fname); 

/*
* Takes in a root node of an xml document and returns the node that points to the data node.
*/
rapidxml::xml_node<> * descendToItem(rapidxml::xml_node<> * root_node);
