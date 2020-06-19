cmake_minimum_required(VERSION 3.2)
project(components C CXX)


set(HEADERS ray.hpp ray_list.hpp project.hpp)

set(SOURCE_FILES
    ray.cpp
    ray_list.cpp
    ${HEADERS}
)


add_library(components SHARED STATIC ${SOURCE_FILES})

install(TARGETS components DESTINATION ${ONETRACER_INSTALL_LIB_DIR})
install(FILES ${HEADERS} DESTINATION ${ONETRACER_INSTALL_INCLUDE_DIR})

set_target_properties(components PROPERTIES LINKER_LANGUAGE CXX)