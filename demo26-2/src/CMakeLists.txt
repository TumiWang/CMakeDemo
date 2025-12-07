# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

# 设置需要使用的语言
project(demo26-2 LANGUAGES C CXX OBJC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(test_gui MACOSX_BUNDLE
    main.m
    AppDelegate.h
    AppDelegate.m
    mycontent.txt
)

set_source_files_properties(mycontent.txt PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

if(CMAKE_GENERATOR STREQUAL "Xcode")
    # 使用Xcode 则添加 文件 MainMenu.xib -- 需要编译
    # target_sources 命令会向TARGET中添加 源文件
    target_sources(test_gui PRIVATE MainMenu.xib)
    # 设置 MainMenu.xib 的编译产物在最终的App包的位置
    set_source_files_properties(
        MainMenu.xib 
        PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
    )
else()
    # 不使用Xcode 则不编译文件 MainMenu.xib
    # 而是，使用预编译好的 MainMenu.nib
    target_sources(test_gui PRIVATE ../precompile/MainMenu.nib)
    # 设置 预编译好的 MainMenu.nib 的编译产物在最终的App包的位置
    set_source_files_properties(
        ../precompile/MainMenu.nib 
        PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
    )
endif()

set_target_properties(
    test_gui PROPERTIES
    # app的名称为 TestGui -- 这个在 info.plist 文件中也有
    OUTPUT_NAME TestGui
    # 设置 plist文件
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/info.plist
    XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
)

# 依赖的framework
target_link_libraries(
    test_gui PRIVATE
    "-framework Foundation"
    "-framework AppKit"
)

install(TARGETS test_gui DESTINATION ${CMAKE_HOST_SYSTEM_PROCESSOR})