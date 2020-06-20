cmake_minimum_required(VERSION 3.2)
project(onetracer_tests)

add_subdirectory(lib/googletest/)
add_definitions(-DBOOST_LOG_DYN_LINK)

include_directories(${ONETRACER_HEADERS_DIR})
include_directories(lib/googletest/)

set(SOURCE_FILES main.cpp src/ray_test.cpp src/ray_list_test.cpp 
                src/input_reader_test.cpp src/sphere_tracer_test.cpp
                src/output_writer_test.cpp src/input_reader_test.cpp)

add_executable(onetracer_tests ${SOURCE_FILES})

set(Boost_USE_STATIC_LIBS        OFF)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and 
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs 
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF) 
find_package(Boost 1.5 COMPONENTS date_time filesystem system log log_setup REQUIRED)
if(Boost_FOUND)   
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(... ${Boost_LIBRARY_DIRS})
    
endif()

target_link_libraries(onetracer_tests components gtest gmock ${Boost_LIBRARIES})


install(TARGETS onetracer_tests DESTINATION bin)