cmake_minimum_required(VERSION 3.5)

project("parse-reach")

# Set C99 standard
if (NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif()

# Set C++14 standard
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Add Executables
add_executable(runNode tests/run_nodes_test.cpp src/array_transform.cpp src/xml_parser.cpp)
ament_target_dependencies (
    runNode
    rclcpp
    geometry_msgs
)

# Install
install(TARGETS
    runNode
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
