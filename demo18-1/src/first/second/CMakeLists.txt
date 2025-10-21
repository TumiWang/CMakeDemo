# 文件 src/first/second/CMakeLists.txt

if (TARGET Boost::locale)
    message(STATUS "Boost::locale is found in second")
else()
    message(STATUS "Boost::locale is NOT found in second")
endif()