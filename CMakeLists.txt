cmake_minimum_required(VERSION 3.17)
project(ES_filesystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(ES_filesystem main.cpp ES/filesystem/content_tools.hpp ES/filesystem/printing_tools.hpp ES/filesystem/navigation_tools.hpp)