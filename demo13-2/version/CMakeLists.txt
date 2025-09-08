# 文件 version/CMakeLists.txt

# 主版本号 根据需要自己修改
set(MAJOR_VERSION 1)

# 次版本号 根据需要自己修改
set(MINOR_VERSION 0)

# 通过计算git的提交次数 当作修订版本号
# 当然，如果当前代码没有使用git管理这里会失败
execute_process(
    COMMAND git rev-list --count HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE REVESION_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 编译版本号 -- 只有Windows使用, 根据需要自己修改
set(BUILD_VERSION 0)

if(WIN32)
    configure_file(resource.rc.in resource.rc @ONLY)
    add_library(version_info OBJECT ${CMAKE_CURRENT_BINARY_DIR}/resource.rc)
    target_include_directories(version_info PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
else()
    configure_file(version.h.in version.h @ONLY)
    add_library(version_info OBJECT version.cpp)
    target_include_directories(version_info PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
endif()