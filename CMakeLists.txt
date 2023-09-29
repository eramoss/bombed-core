cmake_minimum_required(VERSION 3.26)
project(BombedCore)

set(CMAKE_CXX_STANDARD 20)

add_executable(BombedCore src/main.cpp)
#add_executable(AllTests tests/Character.cpp
#        tests/Player.cpp)


enable_testing()
add_executable(PlayerTests tests/Player.cpp)
add_test(PlayerTests PlayerTests)
add_executable(CharacterTests tests/Character.cpp)
add_test(CharacterTests CharacterTests)