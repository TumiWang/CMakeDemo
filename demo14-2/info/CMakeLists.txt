# 文件 info/CMakeLists.txt

add_library(FIBONACCI::info SHARED IMPORTED GLOBAL)

if (WIN32)
    set(SYSTEM_DIR "Windows")
    set(AARCH_DIR ${CMAKE_VS_PLATFORM_NAME})
elseif (LINUX)
    set(SYSTEM_DIR "linux")
    set(AARCH_DIR ${CMAKE_SYSTEM_PROCESSOR})
elseif (APPLE)
    set(SYSTEM_DIR "MacOS")
    set(AARCH_DIR ${CMAKE_SYSTEM_PROCESSOR})
endif ()

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/${SYSTEM_DIR}/${AARCH_DIR})

if (NOT EXISTS ${LIB_DIR})
    message(FATAL_ERROR "缺少该平台的第三方库")
endif ()

set_target_properties(FIBONACCI::info PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
    # CMAKE_SHARED_LIBRARY_PREFIX 是动态库的前缀 例如在
    IMPORTED_LOCATION "${LIB_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}info${CMAKE_SHARED_LIBRARY_SUFFIX}"
)

if (WIN32)
    # Windows平台还需要设置dll对应的lib
    set_target_properties(FIBONACCI::info PROPERTIES
        IMPORTED_IMPLIB "${LIB_DIR}/info${CMAKE_IMPORT_LIBRARY_SUFFIX}"
    )
endif ()

# 下面是cmake --install 的行为
# 需要注意的是 FIBONACCI::info 是导入类型，所以不能使用 install(TARGETS ...)
install(FILES "${LIB_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}info${CMAKE_SHARED_LIBRARY_SUFFIX}" DESTINATION .)