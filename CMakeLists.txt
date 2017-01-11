cmake_minimum_required(VERSION 3.6)
project(Combat_Simulator_2_0)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable(Combat_Simulator_2_0 ${SOURCE_FILES})