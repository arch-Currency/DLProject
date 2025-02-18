cmake_minimum_required(VERSION 3.30)
project(DLProject)

set(CMAKE_CXX_STANDARD 23)

add_library(core SHARED
        src/core/tensor.cpp
        src/core/utils.cpp
)
target_include_directories(core PUBLIC
        src/core
)

add_executable(DLProject src/main.cpp)
target_link_libraries(DLProject PRIVATE core)
target_include_directories(DLProject PRIVATE
        src/core
)

