cmake_minimum_required(VERSION 3.17)

project(MathLib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wno-deprecated-declarations")

enable_testing()
add_subdirectory(tests)

set(HEADERS
   lib/Math.h
)
set(SOURCES
   lib/Math.cpp
)

add_library(core ${SOURCES} ${HEADERS})

target_include_directories(core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/lib    
)

