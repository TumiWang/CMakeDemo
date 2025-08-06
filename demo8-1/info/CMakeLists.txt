# 文件 info/CMakeLists.txt

set(INFO_SOURCES
    info.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

# add_library定义的库可以明确的指定是动态库还是静态库
# 例如，下面就是指定 my_info为静态库
# add_library(my_info STATIC ${INFO_SOURCES})
# 当然，实际上，我们使用下面这句，定义my_info为动态库
add_library(my_info SHARED ${INFO_SOURCES})

target_compile_definitions(my_info PRIVATE MY_INFO_IMPL)