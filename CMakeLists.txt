cmake_minimum_required(VERSION 3.10)

project(logger)

add_library(logger)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(logger PRIVATE src/logger.cpp)
