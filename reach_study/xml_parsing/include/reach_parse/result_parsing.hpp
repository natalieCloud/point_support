#ifndef PS_RESULT_THREADING_H
#define PS_RESULT_THREADING_H

#include "research_structs.hpp"
#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_array.hpp"

#include <stdio.h>

#include <thread>
#include <mutex>
#include <map>
#include <vector>

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
    static std::vector<_Float64> getScoreData(geometry_msgs::msg::PoseArray poseKeys, 
        std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
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
    static void populateResults(int start, int end, int max, geometry_msgs::msg::PoseArray poseKeys,
        std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        _Float64 * results);

    /**
     * @brief Puts the pose data into the poseData (struct) format to be used as a key! for the map!
     * 
     * @param pose: A pose that will act as the key in a data set in reachStudyMap once converted into 
     * a poseData struct!
     * 
     * @returns: The pose data struct that contains the pose data and is able to be used as a key in the map!
     */ 
    static PS_RESTRUCTS_H::Restructs::PoseData getKey(geometry_msgs::msg::Pose * pose);

};

} // namespace Scorter


#endif // PS_RESULT_THREADING_H