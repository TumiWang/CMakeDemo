# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test main.cpp)

# cmake 支持 if 这个逻辑判断 后面的括弧就是判断条件
# 下面这句的判断条件是判断是否定义了cmake的变量TEST_CONTENT
if (DEFINED TEST_CONTENT)
    # 下面这句中的两个 TEST_CONTENT 的意义不一样，实际上它们没必要名称一致
    # (只是我觉得名称一致更能让人注意，并且逻辑意义一致时使用相同名字也是很多开源项目的做法)
    # 第一个 TEST_CONTENT 是 c++ 的宏
    # 第二个 TEST_CONTENT 是 cmake的变量
    #     ${TEST_CONTENT} 是获取变量的内容
    #     修改 cmake的变量TEST_CONTENT 一般使用set命令，例如
    #     set(TEST_CONTENT 100)
    target_compile_definitions(test PUBLIC TEST_CONTENT=${TEST_CONTENT})
# 表示 if 条件结束，注意后面有个括弧
# 这个括弧中的内容相当于注释，这里我省略了
# 很多项目在这个括弧中写 if 条件的内容
# 这样的好处是能够方便的看出来 endif和哪里if对应
# 这在if嵌套时比较有用 --- 阅读上
endif()