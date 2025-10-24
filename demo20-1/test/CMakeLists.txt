# 文件 test/CMakeLists.txt

add_executable(test main.cpp)

# 虽然看上去 test 只使用了 wrapper
# 但是 链接时，需要 info
target_link_libraries(test PRIVATE wrapper info)

install(TARGETS test DESTINATION .)