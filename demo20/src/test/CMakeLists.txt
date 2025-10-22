# 文件 src/test/CMakeLists.txt

add_executable(test main.cpp)

target_link_libraries(
    test PRIVATE
    module1
    module3
)