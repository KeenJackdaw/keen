add_executable(testTriangle testTriangle.cpp
        HelloTriangleApplication.cpp
)

target_include_directories(testTriangle PRIVATE include)
target_link_libraries(testTriangle PRIVATE glfw Vulkan::Vulkan)