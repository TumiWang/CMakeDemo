# 文件 wrapper/CMakeLists.txt

add_library(wrapper SHARED wrapper.cpp)

target_include_directories(
    wrapper PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(wrapper PRIVATE info)

set_target_properties(
    wrapper PROPERTIES
    # 修改了这句
    INSTALL_RPATH $<IF:$<PLATFORM_ID:Darwin>,@loader_path/lib,$ORIGIN/../lib/lib>
)

install(TARGETS wrapper)