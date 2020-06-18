cmake_minimum_required(VERSION 3.2)
project(onetracer)

add_subdirectory(components)
set(SOURCE_FILES main.cpp)

add_executable(onetracer ${SOURCE_FILES})
target_link_libraries(onetracer components)

install(TARGETS onetracer DESTINATION ${ONETRACER_INSTALL_BIN_DIR})