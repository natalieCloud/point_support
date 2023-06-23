#include "array_transform.hpp"

namespace ReachArray {

    // Eigen::Quaternion<_Float64> ArrayTF::getQuaternion(_Float64 * poseArray) {

        
    // }

    Eigen::Isometry3d ArrayTF::getIsometry(_Float64 * poseArray) {
        Eigen::Matrix4d matrix(poseArray); // Passes the pose array information into a matrix 


        Eigen::Isometry3d poseMatrix;
        

        return poseMatrix;
    }

} //namespace ReachArray