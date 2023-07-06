#include "../include/reach_parse/result_parsing.hpp"

/**
 * @author Natalie Chmura
 * 
 * @brief This contains a function that will use threading to parse the
 * information from the xml_parser file and returns an array of scores per
 * pose array!
 */

namespace Scorter {

std::mutex sharedMutex;

std::vector<_Float64> Retriever::getScoreData(geometry_msgs::msg::PoseArray poseKeys,
        std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        int size) {
    
    std::vector<_Float64> results;
    _Float64 resultArr[size];
    _Float64 * arrPtr = resultArr;

    int num_threads = std::thread::hardware_concurrency();
    if(!num_threads) {num_threads++;}

    int inc_size = size/num_threads + 1;

    std::vector<std::thread> threads;
    threads.reserve(num_threads);

    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back(
                std::thread {Retriever::populateResults,
                (i * inc_size), ((i + 1) * inc_size), size, poseKeys, reachStudyMap, arrPtr}
        );
    }
    for (auto& t : threads) {
        t.join();
    }

    results.insert(results.end(), &resultArr[0], &resultArr[size]);
    return results;
}

void Retriever::populateResults(int start, int end, int max, geometry_msgs::msg::PoseArray poseKeys,
        std::map<PS_RESTRUCTS_H::Restructs::PoseData, PS_RESTRUCTS_H::Restructs::ResultData> reachStudyMap,
        _Float64 * results) {

    std::lock_guard<std::mutex> lock(sharedMutex);
    for (int i = start; i < end && i < max; i++) {
        geometry_msgs::msg::Pose * temp = &poseKeys.poses[i];
        results[i] = reachStudyMap[Retriever::getKey(temp)].score;
    }

}

PS_RESTRUCTS_H::Restructs::PoseData Retriever::getKey(geometry_msgs::msg::Pose * pose) {
    PS_RESTRUCTS_H::Restructs::PoseData poseD;
    poseD.translation.x() = pose->position.x;
    poseD.translation.y() = pose->position.y;
    poseD.translation.z() = pose->position.z;
    poseD.quater.x() = pose->orientation.x;
    poseD.quater.y() = pose->orientation.y;
    poseD.quater.z() = pose->orientation.z;
    poseD.quater.w() = pose->orientation.w;
    return poseD;
}

} //namespace Scorter