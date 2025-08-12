# 文件 info/CMakeLists.txt

set(INFO_SOURCES
    info.cpp
    # ... 当然这里可以包含更多源文件, 如果需要的话
)

add_library(my_info SHARED ${INFO_SOURCES})

target_compile_definitions(my_info PRIVATE MY_INFO_IMPL)
target_include_directories(my_info PUBLIC ${CMAKE_SOURCE_DIR}/include)

install(TARGETS my_info DESTINATION .)