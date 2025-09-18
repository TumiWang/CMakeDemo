# 文件 test/CMakeLists.txt

add_executable(test main.cpp)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(test PUBLIC info)
target_link_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/lib/linux-x86_64)