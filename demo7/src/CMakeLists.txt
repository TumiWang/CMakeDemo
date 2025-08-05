# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    # msvc编译时，默认适用本地编码。但代码实际使用的是Utf-8
    # 为了避免这个问题，强制msvc适用utf-8编码
    add_compile_options(/utf-8)
endif()

set(INFO_SOURCES
    info.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

# 定义目标库 my_info -- 这里没有定义约束是动态库还是静态库
# 如果 BUILD_SHARED_LIBS 变量的值是 ON
# 则，my_info 是动态库
# 如果 BUILD_SHARED_LIBS 变量的值是 OFF
# 则，my_info 是静态库
# BUILD_SHARED_LIBS 相当于 bool类型，默认值为 ON
add_library(my_info ${INFO_SOURCES})

# 这句中 PRIVATE 的含义是 编译my_info的所有源文件都定义了宏 MY_INFO_IMPL
# 但使用 my_info库的 test (就是下面的可执行程序) 的所有源文件都没有定义宏 MY_INFO_IMPL
# 除了 PRIVATE 外，还有 INTERFACE 和 之前使用过的 PUBLIC
# 这个细节的讨论参考附录一
target_compile_definitions(my_info PRIVATE MY_INFO_IMPL)

if (BUILD_SHARED_LIBS)
    # 这里使用 PUBLIC
    # my_info库和依赖它的(例如下面的可执行程序 test)都所有源文件都定义了宏 MY_INFO_SHARED_LIBS
    target_compile_definitions(my_info PUBLIC MY_INFO_SHARED_LIBS)
endif()

set(TEST_SOURCES
    main.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

add_executable(test ${TEST_SOURCES})

# 这个表示 test 链接库 my_info
target_link_libraries(test PUBLIC my_info)