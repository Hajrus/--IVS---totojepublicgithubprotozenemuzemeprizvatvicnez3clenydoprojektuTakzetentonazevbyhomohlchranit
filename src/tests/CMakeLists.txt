cmake_minimum_required(VERSION 3.17)

set(SOURCES
    MathTest.cpp
)

add_subdirectory(googletest-master)
add_executable(MathTest ${SOURCES})
target_link_libraries(MathTest PUBLIC
    gtest_main
    core
)

add_test(
    NAME MathTest
    COMMAND MathTest
)