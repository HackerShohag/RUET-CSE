cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(ExampleGtest LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        bf66935e07825318ae519675d73d0f3e313b3ec6
)

# Show progress of the fetch operation
FetchContent_MakeAvailable(googletest)

set(SOURCE_FILES 
    main.cpp
    src/example.cpp
    src/triangle.cpp
)

set(HEADER_FILES 
    include/example.h
    include/triangle.h
)

# Add the executable and link source files
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

#include headers
include_directories(include)
