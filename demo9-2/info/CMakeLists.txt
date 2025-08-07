# 文件 info/CMakeLists.txt

set(INFO_SOURCES
    info.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

add_library(my_info SHARED ${INFO_SOURCES})

target_compile_definitions(my_info PRIVATE MY_INFO_IMPL)
target_include_directories(my_info PUBLIC ${CMAKE_SOURCE_DIR}/include)

# 安装 test
# DESTINATION 是安装位置
# 如果不设置，使用默认值 lib
# 对于不同类型的TARGETS 默认值不同
# my_info是库 所以默认值为 lib
# 这个通常是相对路径
# 相对路径的根路径为 执行 cmake --install时
# 使用 --prefix 指定 参加rebuild.sh中的注释
install(TARGETS my_info DESTINATION .)