# 文件 test/CMakeLists.txt

add_executable(test main.cpp)

target_link_libraries(test PRIVATE wrapper)

set_target_properties(
    test PROPERTIES
    INSTALL_RPATH $<IF:$<PLATFORM_ID:Darwin>,@executable_path/../lib,$ORIGIN/../lib>
)

# 把可执行程序 test 安装到默认位置 -- 通常是bin目录
install(TARGETS test)