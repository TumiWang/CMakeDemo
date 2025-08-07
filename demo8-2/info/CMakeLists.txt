# 文件 info/CMakeLists.txt

set(INFO_SOURCES
    info.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

add_library(my_info SHARED ${INFO_SOURCES})

target_compile_definitions(my_info PRIVATE MY_INFO_IMPL)

# target_include_directories 为编译目标设置头文件的搜索目录
# 第二个参数 在之前的文章中介绍过意义
#   PUBLIC 是因为 my_info和使用它的目标都需要使用这里设置的头文件搜索目录
# 可以指定多个目录，这里只指定了一个
#   如果指定了多个需要要空格分割
# CMAKE_CURRENT_SOURCE_DIR 是 cmake 的内置变量
#   表示的是当前文件所在的目录的全路径
target_include_directories(my_info PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# 当然也可以使用下面这句
# 下面的变量CMAKE_SOURCE_DIR 代表的是根CMakeLists.txt文件所在的全路径
# target_include_directories(my_info PUBLIC ${CMAKE_SOURCE_DIR}/include)