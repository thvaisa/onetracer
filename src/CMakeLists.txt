cmake_minimum_required(VERSION 3.2)
project(onetracer)

#add_subdirectory(division)
set(SOURCE_FILES main.cpp)

add_executable(onetracer ${SOURCE_FILES})
#target_link_libraries(divider division)
install(TARGETS onetracer DESTINATION ${ONETRACER_INSTALL_BIN_DIR})
