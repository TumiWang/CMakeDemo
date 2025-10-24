# 文件 test/CMakeLists.txt

add_executable(test main.cpp)

target_link_libraries(test PRIVATE wrapper)

install(TARGETS test DESTINATION .)