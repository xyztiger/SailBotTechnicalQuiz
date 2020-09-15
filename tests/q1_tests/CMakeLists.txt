include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runQ1Tests
        StandardCalcTest.cpp)

target_link_libraries(runQ1Tests gtest gtest_main)
target_link_libraries(runQ1Tests q1)
