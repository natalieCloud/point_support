#ifndef POINT_SUPPORT_XML_PARSER_H
#define POINT_SUPPORT_XML_PARSER_H

#include "../include/rapidxml.hpp"

#include <string>

/**
 * TODO:
 * Change the above includes in a way that does not depend on the file structure currently 
 * held. i.e figure out a way for the rapidxml.hpp to be pulled into whatever program may use
 * this code if it ends up being ported into something else.
*/

/**
 * XML STUCTURE:
 * 
 * <xml version...>
 * <!DOCTYPE...>
 * <boost_serilization...>
 * <db ... >
 *   <results ...>
 *       <count>
 *       <item_version ...>
 *       <item_class_id>
 *           <count>
 *           <item_version>
 *           <item>
 *               <reached>
 *               <goal>
 *                   <matrix>
 *                       <count>
 *                       <item>...</item>
 *                       <item>...</item>
 *                       x16 (overall, 14 more)
 *                   </matrix>
 *               </goal>
 *               <score>...</score>
 *           </item>
 *           repeat till the end of the file for num points in count (at this level)
*/

namespace reachXML {

class xmlParser {
    public:
        /**
        * Takes in the name of an xml file as a param, and returns a list of structs
        * that contain the pose array as well as the reachability and score.
        */
        static void parseXML(const std::string fname); 

    private:
        /**
        * Takes in a root node of an xml tree and returns the node that points to 
        * the first data node (i.e. the second "<item>").
        */
        static rapidxml::xml_node<> * descendToItem(rapidxml::xml_node<> * root_node);

};

/**
 * The struct that contains the pose and score data.
*/
struct poseData {
    _Float64 pose [16]; // Isometry3D representation of the pose
    int reachResult; // Is the pose considered "reachable", 0 no 1 yes
    _Float64 reachScore; // Score for the reachability of the pose
};

} //namespace reachXML 

#endif // POINT_SUPPORT_XML_PARSER_H