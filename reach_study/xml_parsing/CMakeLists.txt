#CMakeLists.txt : CMake project for xml parsing

cmake_minimum_required(VERSION 3.5)

project("ReachParse")

add_library(ReachParse STATIC src/array_transform.cpp src/xml_parser.cpp 
    include/reach_parse/array_transform.hpp include/reach_parse/xml_parser.hpp)

install(TARGETS ReachParse DESTINATION lib/xml_parser)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ReachParse PROPERTY CXX_STANDARD 20)
endif()

