cmake_minimum_required(VERSION 3.26)
project(BombedCore)

set(CMAKE_CXX_STANDARD 20)

add_executable(BombedCore src/main.cpp)
add_executable(AllTests tests/Character.cpp)

enable_testing()
add_test(AllTests AllTests)