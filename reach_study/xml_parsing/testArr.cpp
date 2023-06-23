#include "array_transform.hpp"

#include <iostream>
#include <iomanip>

/**
 * Used in manual testing, the actual func used for these tests will actually be
 * private in the final class and thus this file will no longer be able to be used! 
 */

int main(int argc, char **argv) {

    _Float64 arr[16];

    arr[0] = 1.0;
    arr[1] = 0.0;
    arr[2] = 0.0;
    arr[3] = 0.0;
    arr[4] = 0.0;
    arr[5] = 1.0;
    arr[6] = 0.0;
    arr[7] = 0.0;
    arr[8] = 0.0;
    arr[9] = 0.0;
    arr[10] = 1.0;
    arr[11] = 0.0;
    arr[12] = 4.0;
    arr[13] = 3.0;
    arr[14] = 2.0;
    arr[15] = 1.0;

    Eigen::Matrix4d m(arr);

    std::setprecision(17);
    std::cout << m << std::endl;

    Eigen::Matrix3d t = m.block<3, 3>(0,0);
    std::cout << t << std::endl;

    Eigen::Vector3d v = m.block<3, 1>(0, 3);
    std::cout << v << std::endl;

    return 0;
}