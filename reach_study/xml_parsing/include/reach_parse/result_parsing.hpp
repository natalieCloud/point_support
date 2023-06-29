#ifndef PS_RESULT_THREADING_H
#define PS_RESULT_THREADING_H

#include "research_structs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_array.hpp"

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
 * @brief Score-Sorter [descending into lame pun namespaces now]
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
     * @param results: An array that contains all of the return scores indexed in the same manner
     * as the poseKey results! //TODO: Make this last param into a return type? Not as nessesary as
     * in the whole client file but might be useful here!
     */
    static void getScoreData(geometry_msgs::msg::PoseArray * poseKeys, 
        std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        _Float64 * results);

    private:

    static void populateResults(int start, int end, int max, geometry_msgs::msg::PoseArray * poseKeys,
        std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        _Float64 * results);

};

} // namespace Scorter


#endif // PS_RESULT_THREADING_H