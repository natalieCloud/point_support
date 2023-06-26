#include "array_transform.hpp"

#include <iostream>
#include <iomanip>

/**
 * Used in manual testing, the actual func used for these tests will actually be
 * private in the final class and thus this file will no longer be able to be used! 
 */

int main(int argc, char **argv) {

    _Float64 arr[16];

    arr[0] = 0.876905918121337891;
    arr[1] = -0.212268337607383728;
    arr[2] = -0.431251943111419678;
    arr[3] = 0.0;
    arr[4] = 0.0000000149011611349835284;
    arr[5] = 0.897204041481018066;
    arr[6] = -0.441616535186767689;
    arr[7] = 0.0;
    arr[8] = 0.480662077665328979;
    arr[9] = 0.387256145477295033;
    arr[10] = 0.786763489246368408;
    arr[11] = 0.0;
    arr[12] = 2.42234468460083008;
    arr[13] = -0.360797971487045288;
    arr[14] = 1.23888421058654785;
    arr[15] = 1.0;

    _Float64 * aptr = arr;

    // Eigen::Matrix4d m(arr);

    // std::setprecision(17);
    // std::cout << m << std::endl;

    // Eigen::Matrix3d t = m.block<3, 3>(0,0);
    // std::cout << t << std::endl;

    // Eigen::Vector3d v = m.block<3, 1>(0, 3);
    // std::cout << v << std::endl;

    // Eigen::Isometry3d poseMatrix = Eigen::Isometry3d::Identity();

    // poseMatrix.translate(v.matrix());
    // std::cout << poseMatrix.translation() << std::endl;

    // std::cout << poseMatrix.matrix() << std::endl;

    // poseMatrix.rotate(t.matrix());
    // std::cout << poseMatrix.rotation() << std::endl;

    // std::cout << poseMatrix.matrix() << std::endl;
    Eigen::Quaternion<_Float64> quat = POINT_SUPPORT_ARRAY_TRANSFORM_H::ReachArray::ArrayTF::getQuaternion(aptr);
    Eigen::Vector3d mat = POINT_SUPPORT_ARRAY_TRANSFORM_H::ReachArray::ArrayTF::getTranslation(aptr);
    quat.normalize();
    std::cout << "This is the pose quaternion: \n";
    std::cout << quat.normalized() << std::endl;

    std::cout << "This is the pose translation: \n";
    std::cout << mat << std::endl;
    return 0;
}