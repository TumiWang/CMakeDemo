# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test main.cpp name.cpp)

# add_definitions(-DCPP_FANTASY_CHINESE)
# 上面那句如果没有注释掉, 则表示，所有的编译目标都添加 宏 CPP_FANTASY_CHINESE 定义
# 虽然，我们这个例子中只有一个编译目标 -- test
# 但，cmake是可以配置多个编译目标的。
# 这里的编译目标是指 可执行程序、动态库和静态库等。
# 所以，不推荐使用 add_definitions -- 会影响所有编译目标

# add_compile_definitions(-DCPP_FANTASY_CHINESE)
# 除了 add_definitions, 还可以使用 add_compile_definitions
# add_compile_definitions 从3.12开始支持
# 上面定义宏时，有个前缀 -D
# add_compile_definitions 可以不用这个前缀，像下面这样:
# add_compile_definitions(CPP_FANTASY_CHINESE)
# add_definitions 和 add_compile_definitions 可以同时定义多个宏
# 中间使用空格 -- cmake的语法中，通常使用空格分割参数
# 下面这句定义的两个宏 CPP_FANTASY_CHINESE 和 CPP_FANTASY_ENGLISH
# add_compile_definitions(CPP_FANTASY_CHINESE CPP_FANTASY_ENGLISH)
# add_compile_definitions 也是影响所有编译目标，所以也不推荐

target_compile_definitions(test PUBLIC CPP_FANTASY_CHINESE)
# target_compile_definitions 和 add_compile_definitions 的唯一区别就是
# target_compile_definitions 只影响一个目标 -- 就是第一个参数(上面例子中就是 test)
# 第二个参数 先认为是固定的 PUBLIC -- 这个后面介绍编译目标是库文件时再介绍
# 后面的参数和 add_compile_definitions 一样 -- 包括可选的省略 -D
# 注意: target_compile_definitions 只影响当个目标
# 如果有两个目标: test1 和 test2, 则需要写两次:
# target_compile_definitions(test1 PUBLIC CPP_FANTASY_CHINESE)
# target_compile_definitions(test2 PUBLIC CPP_FANTASY_CHINESE)
# 可以有时觉得麻烦，这时就考虑 add_compile_definitions 或 add_definitions
