# 文件 test/CMakeLists.txt

add_executable(test main.cpp)

target_link_libraries(test PRIVATE wrapper)

set_target_properties(
    test PROPERTIES
    INSTALL_RPATH $<IF:$<PLATFORM_ID:Darwin>,@executable_path/../lib,$ORIGIN/../lib>
)

# # set_target_properties 命令能同时设置多个属性
# # set_property 能给一个属性设置多个值(相当于数组)
# set_property(
#     TARGET test
#     PROPERTY
#     INSTALL_RPATH
#     # 换一种生成器表达式的写法
#     # 个人觉得这种更简洁
#     # 但要注意 实际上和 $<IF:...> 并不等效
#     #     -- PLATFORM_ID 不是 Darwin，并不代表一定是 Linux。
#     $<$<PLATFORM_ID:Darwin>:@executable_path/../lib>
#     $<$<PLATFORM_ID:Darwin>:@executable_path/../lib/lib>
#     $<$<PLATFORM_ID:Linux>:$ORIGIN/../lib>
#     $<$<PLATFORM_ID:Linux>:$ORIGIN/../lib/lib>
# )

install(TARGETS test)