cmake_minimum_required (VERSION 2.8)
project(zmqsample)

add_definitions("-Wno-deprecated-declarations")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#enable c++ 11
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

#zeromqness
find_package(ZMQ REQUIRED)
include_directories(${ZMQ_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

set(server_sources
    server.cpp
)

set(client_sources
    client.cpp
)

add_executable(server ${server_sources})
add_executable(client ${client_sources})

target_link_libraries(server ${ZMQ_LIBRARIES})
target_link_libraries(client ${ZMQ_LIBRARIES})
