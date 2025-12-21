cmake_minimum_required(VERSION 3.10)
project(logger)

# 1. Включение модуля стандартных путей установки
include(GNUInstallDirs)

add_library(logger)

# 2. Обновлённые директории включения с генераторными выражениями
target_include_directories(logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(logger PRIVATE src/logger.cpp)

# 3. Установка самой библиотеки
install(TARGETS logger
    EXPORT logger-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 4. Установка заголовочных файлов
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/logger
    FILES_MATCHING PATTERN "*"
)

# 5. Экспорт конфигурации для find_package (опционально)
install(EXPORT logger-targets
    FILE logger-config.cmake
    NAMESPACE logger::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/logger
)
