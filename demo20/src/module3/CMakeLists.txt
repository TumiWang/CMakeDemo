# 文件 src/module3/CMakeLists.txt

add_library(module3 impl.cpp)

set(EXPORT_DECORATED MODULE3_EXPORT_DECORATED)
set(EXPORT_MODULE_IMPL MODULE3_IMPL)

configure_file(${CMAKE_SOURCE_DIR}/export_decorated.h.in export_decorated.h @ONLY)

target_include_directories(
    module3 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)

target_compile_definitions(module3 PRIVATE MODULE3_IMPL)

target_link_libraries(module3 PUBLIC module2)