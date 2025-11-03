# 文件 src/module1/CMakeLists.txt

add_library(module1 impl.cpp)

set(EXPORT_DECORATED MODULE1_EXPORT_DECORATED)
set(EXPORT_MODULE_IMPL MODULE1_IMPL)

configure_file(${CMAKE_SOURCE_DIR}/export_decorated.h.in export_decorated.h @ONLY)

target_include_directories(
    module1 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)

target_compile_definitions(module1 PRIVATE MODULE1_IMPL)