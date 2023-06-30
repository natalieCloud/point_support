cmake_minimum_required(VERSION 3.5)

project("result-process")

add_library(result-process STATIC)

install(TARGETS result-process DESTINATION lib/results)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET reach_parse PROPERTY CXX_STANDARD 20)
endif()