cmake_minimum_required(VERSION 3.25)
project(ProjectName)

add_subdirectory(matplotplusplus)

add_executable(my_target lab005.cpp)
target_link_libraries(my_target PUBLIC matplot)
