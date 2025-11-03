# 文件 info/CMakeLists.txt

add_library(info SHARED info.cpp)

target_include_directories(
    info PUBLIC
    # info.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 把库 info 安装到默认位置 -- 通常是lib目录
# 因为这次不演示Windows的场景，所以没有指定库类型
install(TARGETS info)