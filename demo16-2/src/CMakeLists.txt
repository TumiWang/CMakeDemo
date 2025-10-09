# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-16-2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS OFF)

set(BOOST_INCLUDE_LIBRARIES "locale")

# 直接使用 add_subdirectory 把第三方库(boost)包含进来
# 看上去比使用FetchContent更简洁吧
# 但需要自己管理 boost的源码了 -- 参考附录四
add_subdirectory(third_party/boost-1.89.0)

add_library(trans SHARED trans.cpp)

target_link_libraries(trans PRIVATE Boost::locale)