# 文件 src/module2/CMakeLists.txt

add_library(module2 impl.cpp)

set(EXPORT_DECORATED MODULE2_EXPORT_DECORATED)
set(EXPORT_MODULE_IMPL MODULE2_IMPL)

configure_file(${CMAKE_SOURCE_DIR}/export_decorated.h.in export_decorated.h @ONLY)

target_include_directories(
    module2 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)

target_compile_definitions(module2 PRIVATE MODULE2_IMPL)