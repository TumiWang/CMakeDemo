# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-16-1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

# 这句是为了解决 boost 编译时没有使用PIC参数的问题
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 这句是为了库默认编译静态库
# 因为boost库是我们自己编译的，所以不需要使用Boost_USE_STATIC_LIBS变量了
set(BUILD_SHARED_LIBS OFF)

# FetchContent 是cmake的一个内置模块
# 这个模块提供了 FetchContent_Declare 和 FetchContent_MakeAvailable 等命令
include(FetchContent)

# 这句是控制boost编译时，只编译 locale这个子模块
#     -- 当然，也会因为依赖原因编译其他的模块
#        但编译的项目比全部编译要少很多
set(BOOST_INCLUDE_LIBRARIES "locale")

# 远端git库
# FetchContent_Declare(
#     boost
#     # github仓库地址 通常应该使用 https的。但我这里因为一些原因使用的 git的
#     # GIT_REPOSITORY https://github.com/boostorg/boost.git
#     GIT_REPOSITORY git@github.com:boostorg/boost.git
#     GIT_TAG        ef7fea34711a189472893b88205b1dd3c275677b # boost-1.89.0
# )

# 没有git的历史提交记录
# FetchContent_Declare(
#     boost
#     # GIT_REPOSITORY https://github.com/boostorg/boost.git
#     GIT_REPOSITORY git@github.com:boostorg/boost.git
#     GIT_SHALLOW    ON
#     GIT_TAG        boost-1.89.0
# )

# 下载链接
FetchContent_Declare(
    boost
    # URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.tar.gz
    URL ${CMAKE_CURRENT_SOURCE_DIR}/boost-1.89.0-cmake.tar.gz
    # 文件进行MD5验证 -- 可选
    # 同理，也可以使用SHA1验证
    # 例如 URL_HASH SHA1=de4a2877ec0d9aae30ece4b2f292d585200df1d0
    # 因为MD5更常用，所以MD5验证还有一种写法，如下:
    # URL_MD5 aaeeb6cfb86e85ce28c8f2f1fc104d75
    URL_HASH MD5=aaeeb6cfb86e85ce28c8f2f1fc104d75
)

# FetchContent_Declare是声明了外部内容
# 以及这个外部内容的获取方式
# 但是 并不会有获取(下载等)的行为
# 在执行 cmake -B <build_dir> -S ...
# 这样的命令时 FetchContent_MakeAvailable 会执行对应的获取(下载)行为
# 在执行 cmake --build ...
# 这样的命令时 FetchContent_MakeAvailable 会执行编译行为
FetchContent_MakeAvailable(boost)

add_library(trans SHARED trans.cpp)

target_link_libraries(trans PRIVATE Boost::locale)