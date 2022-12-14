cmake_minimum_required(VERSION 3.4...3.18)
project(cpp_crash LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(armadillo REQUIRED)
find_path(ARMADILLO_INC armadillo)
message(STATUS "ARMADILLO_INC: [${ARMADILLO_INC}]")
find_library(ARMADILLO_LIB armadillo)
message(STATUS "ARMADILLO_LIB: [${ARMADILLO_LIB}]")

# link_directories(${ARMADILLO_LIB})
add_executable(cpp_crash main.cpp)
include_directories(${ARMADILLO_INC})
target_link_libraries(cpp_crash ${ARMADILLO_LIB})

# find_package(pybind11 REQUIRED)
# pybind11_add_module(cpp_crash cpp_crash.cpp)