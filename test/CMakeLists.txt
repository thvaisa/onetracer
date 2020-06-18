cmake_minimum_required(VERSION 3.2)
project(onetracer_tests)

add_subdirectory(lib/googletest/)

include_directories(${ONETRACER_HEADERS_DIR})
include_directories(lib/googletest/)

set(SOURCE_FILES main.cpp)

add_executable(onetracer_tests ${SOURCE_FILES})
target_link_libraries(onetracer_tests gtest)
install(TARGETS onetracer_tests DESTINATION bin)

