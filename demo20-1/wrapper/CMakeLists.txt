# 文件 wrapper/CMakeLists.txt

add_library(wrapper STATIC wrapper.cpp)

target_include_directories(
    wrapper PUBLIC
    # wrapper.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(wrapper PRIVATE WRAPPER_IMPL)

target_link_libraries(wrapper PUBLIC info)