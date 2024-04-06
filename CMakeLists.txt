cmake_minimum_required(VERSION 3.27)
project(keen)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# dependencies
find_package(glfw3 3.4 REQUIRED) # glfw
find_package(Vulkan 1.3.276 REQUIRED) # vulkan

# source code
add_subdirectory(src)

# test cases
add_subdirectory(test)
