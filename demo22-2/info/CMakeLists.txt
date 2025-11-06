# 文件 info/CMakeLists.txt

set(INFO_SRC
    info.cpp
    # CYGWIN,MSYS,Windows,WindowsCE,WindowsPhone和WindowsStore
    # 都是Windows的编译环境
    $<IF:$<PLATFORM_ID:CYGWIN,MSYS,Windows,WindowsCE,WindowsPhone,WindowsStore>,init_windows.cpp,init_posix.cpp>
    # init_$<IF:$<PLATFORM_ID:CYGWIN,MSYS,Windows,WindowsCE,WindowsPhone,WindowsStore>,windows,posix>.cpp
)

add_library(info SHARED ${INFO_SRC})

target_include_directories(info PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_definitions(info PRIVATE INFO_MODULE_IMPL)

if (WIN32)
    install(TARGETS info RUNTIME DESTINATION .)
else()
    install(TARGETS info LIBRARY DESTINATION .)
endif()