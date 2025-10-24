# 文件 info/CMakeLists.txt

add_library(info SHARED info.cpp)

# 下面两个变量 EXPORT_DECORATED 和 EXPORT_MODULE_IMPL
# 在 export_decorated.h.in 中使用
set(EXPORT_DECORATED INFO_EXPORT_DECORATED)
set(EXPORT_MODULE_IMPL INFO_IMPL)
configure_file(${CMAKE_SOURCE_DIR}/export_decorated.h.in info_export_decorated.h @ONLY)

target_include_directories(
    info PUBLIC
    # info.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
    # info_export_decorated.h 在 ${CMAKE_CURRENT_BINARY_DIR} 中
    ${CMAKE_CURRENT_BINARY_DIR}
)

# 这里 PRIVATE 很重要
target_compile_definitions(info PRIVATE INFO_IMPL)

if (WIN32)
    install(TARGETS info RUNTIME DESTINATION .)
else()
    install(TARGETS info LIBRARY DESTINATION .)
endif()