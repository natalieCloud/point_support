#ifndef PS_RESULT_THREADING_H
#define PS_RESULT_THREADING_H

#include "research_structs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"

#include <stdlib.h>
#include <stdio.h>

#include <thread>
#include <mutex>

/**
 * @author Natalie Chmura
 * 
 * @brief This contains a function that will use threading to parse the
 * information from the xml_parser file and returns an array of scores per
 * pose array!
 */

/**
 * @namespace Scorter
 * 
 * @brief Score-Sorter [descending into lame pun namespaces]
*/
namespace Scorter {

/**
 * @class Retriever
 * 
 * @brief This class contains functions that aid in the sorting and populating the
 * results of the reach_study array!
 */
class Retriever {

    public:

    /**
     * @brief Runs a number of threads through the returned map of score data who assign
     * the returned score result to an associated index in the result array!
     * 
     * @param poseKeys: A poseArray that will act as the keys for the data in the reachStudyMap
     * @param reachStudyMap: A map that contains all of the data pulled from the reach_study in xml_parsing
     * with the keys being of type pose and the results containing the return sucess and score!
     */
    static std::vector<_Float64> * getScoreData(geometry_msgs::msg::Pose * poseKeys, 
        std::map<geometry_msgs::msg::Pose, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        int size);

    private:

    /**
     * @brief Runs through the beginning and end indicies of a list adding the associated key values 
     * to a new "results" list! 
     * 
     * @param poseKeys: A poseArray that will act as the keys for the data in the reachStudyMap
     * @param reachStudyMap: A map that contains all of the data pulled from the reach_study in xml_parsing
     * with the keys being of type pose and the results containing the return sucess and score!
     * @param results: An vector that contains all of the return scores indexed in the same manner
     * as the poseKey results! (Non returnable since the same map needs to be populated without
     * being overwritten! ^^)
     */
    static void populateResults(int start, int end, int max, geometry_msgs::msg::Pose * poseKeys,
        std::map<geometry_msgs::msg::Pose, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        _Float64 * results);

};

} // namespace Scorter


#endif // PS_RESULT_THREADING_H