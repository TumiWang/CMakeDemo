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
)

if(CMAKE_GENERATOR STREQUAL "Xcode")
    target_sources(test_gui PRIVATE MainMenu.xib)
    set_source_files_properties(
        MainMenu.xib 
        PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
    )
else()
    target_sources(test_gui PRIVATE ../precompile/MainMenu.nib )
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
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/info.plist
    XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
)

target_link_libraries(
    test_gui PRIVATE
    "-framework Foundation"
    "-framework AppKit"
)

install(TARGETS test_gui DESTINATION ${CMAKE_HOST_SYSTEM_PROCESSOR})