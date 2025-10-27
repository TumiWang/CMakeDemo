# 文件 wrapper/CMakeLists.txt

add_library(wrapper STATIC wrapper.cpp)

target_include_directories(
    wrapper PUBLIC
    # wrapper.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(wrapper PRIVATE WRAPPER_IMPL)

# 这里虽然使用了 PRIVATE
# 但使用wrapper 的 test 还是会链接 info
# 但如果 上面的 target_include_directories 使用 PRIVATE
# 就会导致 test 在编译时，不能找的文件 wrapper.h
target_link_libraries(wrapper PRIVATE info)