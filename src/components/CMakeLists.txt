cmake_minimum_required(VERSION 3.2)
project(components C CXX)


set(SOURCE_FILES
    ray.hpp
    ray.cpp
)


add_library(components SHARED STATIC ${SOURCE_FILES})

install(TARGETS components DESTINATION ${ONETRACER_INSTALL_LIB_DIR})
install(FILES ray.hpp DESTINATION ${ONETRACER_INSTALL_INCLUDE_DIR})

set_target_properties(components PROPERTIES LINKER_LANGUAGE CXX)