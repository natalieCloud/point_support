#ifndef PS_RESTRUCTS_H
#define PS_RESTRUCTS_H

#include <eigen3/Eigen/Geometry>

#include <stdlib.h>

/**
 * @namespace Restructs
 * 
 * @brief Research Structs   *ba-dum-tssh* 
 */
namespace Restructs {

/**
 * @struct PoseData
 * @brief Struct that contains the pose information
 * 
 * @param translation: A 3x1 vector that represents the pose's xyz coordinates
 * @param quater: A quaternion that represents the pose's rotation
 */
struct PoseData {
    Eigen::Vector3d translation;
    Eigen::Quaternion<_Float64> quater;

    //Operator overloads for use as a key
    //Sorting is pretty arbitrary I think? Like.... one or the other should always differ 
    //for the poses ¯\_(ツ)_/¯  We'll see i.g.......
    bool operator==(const PoseData &p) const {
        return translation == p.translation && quater == p.quater;
    }
    bool operator<(const PoseData &p) const {
        return translation.x() < p.translation.x() || (translation.x() == p.translation.x() && quater.w() == p.quater.w());
    }
};

/**
 * @struct ScoreData
 * @brief Struct that contains the score information for a pose
 * 
 * @param result: A boolean that signals if the pose is reachable (true) or not (false).
 * @param score: The reach score calculated by the reach study
 */
struct ResultData {
    bool reachable;
    _Float64 score;
};
    
/**
 * @struct ReachData
 * @brief Struct that contains the pose and score data.
 * 
 * @param translation: A 3x1 vector that represents the pose's xyz coordinates
 * @param quater: A quaternion that represents the pose's rotation
 * @param reachResult: Is the pose considered "reachable", 0 no 1 yes
 * @param reachScore: Score for the reachability of the pose
 */ 
struct ReachData {
    struct PoseData pose;
    struct ResultData result; 
};

} // namespace Restructs



#endif // POINT_SUPPORT_RESEARCH_STRUCTS_H