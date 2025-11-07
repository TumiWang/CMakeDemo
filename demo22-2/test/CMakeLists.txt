# 文件 test/CMakeLists.txt

set(TEST_SRC
    main.cpp
    util_$<IF:$<PLATFORM_ID:CYGWIN,MSYS,Windows,WindowsCE,WindowsPhone,WindowsStore>,windows,posix>.cpp
    util.cpp
)

add_executable(test ${TEST_SRC})

install(TARGETS test DESTINATION .)