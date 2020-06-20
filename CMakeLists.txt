cmake_minimum_required(VERSION 3.2)

project(onetracer_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(ONETRACER_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ONETRACER_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(ONETRACER_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(COMPONENTS_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/components)

include_directories(${ONETRACER_INSTALL_INCLUDE_DIR})
include_directories(${COMPONENTS_HEADERS_DIR})


add_subdirectory(src)
add_subdirectory(test)


