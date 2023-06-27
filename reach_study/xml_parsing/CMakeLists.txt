cmake_minimum_required(VERSION 3.5)

project("reach-parse")

add_library(reach-parse STATIC src/array_transform.cpp src/xml_parser.cpp 
    include/reach_parse/array_transform.hpp include/reach_parse/xml_parser.hpp)

install(TARGETS reach-parse DESTINATION lib/results)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET reach-parse PROPERTY CXX_STANDARD 20)
endif()

