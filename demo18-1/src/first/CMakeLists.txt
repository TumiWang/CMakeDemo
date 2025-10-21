# 文件 src/first/CMakeLists.txt

# 这里添加了参数 GLOBAL
find_package(Boost COMPONENTS locale GLOBAL)

if (TARGET Boost::locale)
    message(STATUS "Boost::locale is found in first")
else()
    message(STATUS "Boost::locale is NOT found in first")
endif()

add_subdirectory(second)