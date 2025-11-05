# 文件 info/CMakeLists.txt

add_library(info SHARED info.cpp)

target_include_directories(
    info PUBLIC
    # info.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 就是修改了下面这句
install(TARGETS info DESTINATION lib/lib)