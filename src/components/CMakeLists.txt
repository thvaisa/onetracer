cmake_minimum_required(VERSION 3.2)
project(components C CXX)


set(HEADERS ray.hpp ray_list.hpp project.hpp input_reader.hpp 
            sphere_tracer.hpp output_writer.hpp
            domain_code_handler.hpp)

set(SOURCE_FILES
    ray.cpp
    ray_list.cpp
    sphere_tracer.cpp
    output_writer.cpp
    input_reader.cpp
    domain_code_handler.cpp
    ${HEADERS}
)

add_definitions(-DBOOST_LOG_DYN_LINK)

add_library(components SHARED STATIC ${SOURCE_FILES})

install(TARGETS components DESTINATION ${ONETRACER_INSTALL_LIB_DIR})
install(FILES ${HEADERS} DESTINATION ${ONETRACER_INSTALL_INCLUDE_DIR})

set_target_properties(components PROPERTIES LINKER_LANGUAGE CXX)


set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and 
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs 
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF) 
find_package(Boost 1.5 COMPONENTS date_time filesystem system log log_setup REQUIRED)
if(Boost_FOUND)   
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(components ${Boost_LIBRARIES})
endif()