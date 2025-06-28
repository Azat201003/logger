cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# find_library(logger)

add_executable(logger_tests
    main.cpp
)

# Включаем директорию с фикстурами
target_include_directories(logger_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/fixtures
)

# Линковка с нашей библиотекой и gtest
target_link_libraries(logger_tests PRIVATE
    logger
)
