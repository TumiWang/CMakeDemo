# 文件 src/cpp/CMakeLists.txt

add_executable(test_cpp main.cpp)

install(TARGETS test_cpp DESTINATION ${CMAKE_HOST_SYSTEM_PROCESSOR})