add_library(keen_kernel STATIC)

target_sources(keen_kernel
    PRIVATE
        camera/camera.cpp
        driver/vulkan/application.cpp
        driver/vulkan/validation.cpp
        driver/vulkan/extension.cpp
        driver/vulkan/device.cpp
)

target_compile_definitions(keen_kernel
    PUBLIC
        -DKNN_NAMESPACE_BEGIN=namespace\ knn\ {
        -DKNN_NAMESPACE_END=}
    PRIVATE
        -DKEEN=\"KEEN\"
        -DKEEN_VERSION_MAJOR=0
        -DKEEN_VERSION_MINOR=0
        -DKEEN_VERSION_PATCH=1
        -DKEEN_ENGINE=\"KEENGINE\"
)

add_dependencies(keen_kernel keen_math)

target_include_directories(keen_kernel
        PUBLIC include
)
target_link_libraries(keen_kernel PRIVATE keen_math glfw)