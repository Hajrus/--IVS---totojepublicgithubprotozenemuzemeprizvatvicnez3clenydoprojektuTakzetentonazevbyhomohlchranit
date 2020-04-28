cmake_minimum_required(VERSION 3.17)

project(MathLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wno-deprecated-declarations")

enable_testing()

set(HEADERS
   ../lib/Math.h
)
set(SOURCES
   ../lib/Math.cpp
)

add_library(core ${SOURCES} ${HEADERS})

target_include_directories(core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/../lib    
)

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