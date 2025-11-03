# 文件 wrapper/CMakeLists.txt

add_library(wrapper SHARED wrapper.cpp)

target_include_directories(
    wrapper PUBLIC
    # wrapper.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(wrapper PRIVATE info)

set_target_properties(
    wrapper PROPERTIES
    INSTALL_RPATH $<IF:$<PLATFORM_ID:Darwin>,@executable_path/../lib,$ORIGIN/../lib>
)

# 把库 wrapper 安装到默认位置 -- 通常是lib目录
# 因为这次不演示Windows的场景，所以没有指定库类型
install(TARGETS wrapper)