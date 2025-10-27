# 文件 wrapper/CMakeLists.txt

add_library(wrapper SHARED wrapper.cpp)

set(EXPORT_DECORATED WRAPPER_EXPORT_DECORATED)
set(EXPORT_MODULE_IMPL WRAPPER_IMPL)

configure_file(${CMAKE_SOURCE_DIR}/export_decorated.h.in wrapper_export_decorated.h @ONLY)

target_include_directories(
    wrapper PUBLIC
    # wrapper.h 在 ${CMAKE_CURRENT_SOURCE_DIR} 中
    ${CMAKE_CURRENT_SOURCE_DIR}
    # wrapper_export_decorated.h 在 ${CMAKE_CURRENT_BINARY_DIR} 中
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_definitions(wrapper PRIVATE WRAPPER_IMPL)

target_link_libraries(wrapper PRIVATE info)

if (WIN32)
    install(TARGETS wrapper RUNTIME DESTINATION .)
else()
    install(TARGETS wrapper LIBRARY DESTINATION .)
endif()