cmake_minimum_required(VERSION 3.16)
project(SailBotTechnicalQuiz)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp StandardCalc.cpp tests/StandardCalcTests.cpp)
add_executable(SettingUpGoogleTest ${SOURCE_FILES})
target_link_libraries(SettingUpGoogleTest gtest gtest_main)
