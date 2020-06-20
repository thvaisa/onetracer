cmake_minimum_required(VERSION 3.2)
project(onetracer)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_subdirectory(components)
set(SOURCE_FILES main.cpp)

add_executable(onetracer ${SOURCE_FILES})


target_link_libraries(onetracer PRIVATE nlohmann_json::nlohmann_json components)



install(TARGETS onetracer DESTINATION ${ONETRACER_INSTALL_BIN_DIR})


