add_executable(keen keen.cpp)

target_link_libraries(keen PRIVATE keen_kernel keen_math Vulkan::Vulkan)

