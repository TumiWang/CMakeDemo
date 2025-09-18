# 文件 test/CMakeLists.txt

add_executable(test main.cpp)

target_link_libraries(test PUBLIC FIBONACCI::info)

# 下面是 cmake --install 的行为
if (LINUX)
    set_target_properties(test PROPERTIES INSTALL_RPATH "$ORIGIN")
elseif (APPLE)
    set_target_properties(test PROPERTIES INSTALL_RPATH "@executable_path")
endif ()

install(TARGETS test DESTINATION .)