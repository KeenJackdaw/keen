add_library(keen_device STATIC)

target_sources(keen_device
    PRIVATE
        gpu/gpu.cpp
        device.cpp
)

target_compile_definitions(keen_device
        PUBLIC
        -DKND_NAMESPACE_BEGIN=namespace\ knd\ {
        -DKND_NAMESPACE_END=})

target_include_directories(keen_device PUBLIC include)
target_link_libraries(keen_device PRIVATE keen_kernel Vulkan::Vulkan)