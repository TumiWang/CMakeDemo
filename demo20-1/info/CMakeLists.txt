# 文件 info/CMakeLists.txt

add_library(info STATIC info.cpp)

target_include_directories(
    info PUBLIC
    # info.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 这里 PRIVATE 很重要
target_compile_definitions(info PRIVATE INFO_IMPL)