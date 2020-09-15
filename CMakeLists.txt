cmake_minimum_required(VERSION 3.17)
project(SailBotTechnicalQuiz)
#
set(CMAKE_CXX_STANDARD 17)
#
##add_subdirectory(Google_tests)
##
#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#set(SOURCE_FILES q1/main.cpp)
#
#add_executable(SailBotTechnicalQuiz ${SOURCE_FILES})
#target_link_libraries(SailBotTechnicalQuiz gtest gtest_main)

#include_directories(q1)
#
#add_subdirectory(q1)
#add_subdirectory(tests)
#add_subdirectory(tests/lib/googletest-master)

set(SOURCES_FILE main.cpp)
add_executable(q1_run ${SOURCE_FILES})

include_directories(q1)

add_subdirectory(q1)
add_subdirectory(tests)

target_link_libraries(q1_run q1)