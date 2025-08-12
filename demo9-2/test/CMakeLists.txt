# 文件 test/CMakeLists.txt

set(TEST_SOURCES
    test.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

add_executable(test ${TEST_SOURCES})
target_link_libraries(test PUBLIC my_info)

# 安装 test
# DESTINATION 是安装位置
# 如果不设置，使用默认值 bin
# 对于不同类型的TARGETS 默认值不同
# test是可执行文件 所以默认值为 bin
install(TARGETS test DESTINATION .)