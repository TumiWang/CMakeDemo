# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(demo33-2)

if(MSVC)
    add_compile_options(/utf-8)
endif()

include(CTest)

add_executable(demo32 main.cpp)

# add_test(test1 demo32 1)
# add_test(test2 demo32 3)
# add_test(test3 demo32 5)
# add_test(test4 demo32 7)
# add_test(test5 demo32 9)

# foreach(INDEX RANGE 1 5)
#     set_property(TEST test${INDEX} PROPERTY LABELS Test${INDEX} Sum)
# endforeach()

# set_property(TEST test1 PROPERTY LABELS Test1 Sum)
# set_property(TEST test2 PROPERTY LABELS Test2 Sum)
# set_property(TEST test3 PROPERTY LABELS Test3 Sum)
# set_property(TEST test4 PROPERTY LABELS Test4 Sum)
# set_property(TEST test5 PROPERTY LABELS Test5 Sum)

foreach(INDEX RANGE 1 5)
    math(EXPR ARG1 "${INDEX} * 2 - 1")
    add_test(test${INDEX} demo32 ${ARG1})
    set_property(TEST test${INDEX} PROPERTY LABELS Test${INDEX} Sum)
endforeach()
