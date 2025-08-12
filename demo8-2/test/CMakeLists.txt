# 文件 test/CMakeLists.txt

set(TEST_SOURCES
    test.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

add_executable(test ${TEST_SOURCES})
target_link_libraries(test PUBLIC my_info)