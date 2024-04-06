add_library(keen_kernel STATIC camera/camera.cpp model.cpp driver/vulkan/validation.cpp)

target_compile_definitions(keen_kernel
        PUBLIC
        -DKNN_NAMESPACE_BEGIN=namespace\ knn\ {
        -DKNN_NAMESPACE_END=})

add_dependencies(keen_kernel keen_math)

target_include_directories(keen_kernel
        PUBLIC include
)
target_link_libraries(keen_kernel PRIVATE keen_math)