cmake_minimum_required(VERSION 3.16)

project(ROT13 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR_PATH})

add_library(r13 SHARED ${SRC_DIR_PATH}/ROT13.cpp)

add_executable(out ${SRC_DIR_PATH}/main.cpp)

target_include_directories(r13 INTERFACE ${INCLUDE_DIR_PATH})
target_link_libraries(out PRIVATE r13)
