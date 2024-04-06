add_library(keen_math STATIC vec3.cpp)

target_compile_definitions(keen_math
        PUBLIC
        -DKNM_NAMESPACE_BEGIN=namespace\ knm\ {
        -DKNM_NAMESPACE_END=})

target_include_directories(keen_math
        PUBLIC include)