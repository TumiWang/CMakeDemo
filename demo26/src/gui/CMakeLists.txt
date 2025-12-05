# 文件 src/gui/CMakeLists.txt

add_executable(test_gui MACOSX_BUNDLE
    main.m
    AppDelegate.h
    AppDelegate.m
    MainMenu.xib
)

set_source_files_properties(
    MainMenu.xib 
    PROPERTIES
    MACOSX_PACKAGE_LOCATION Resources
)

set_target_properties(
    test_gui PROPERTIES
    OUTPUT_NAME TestGui
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/info.plist
    XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
)

target_link_libraries(test_gui PRIVATE "-framework Foundation")
target_link_libraries(test_gui PRIVATE "-framework AppKit")

install(TARGETS test_gui DESTINATION ${CMAKE_HOST_SYSTEM_PROCESSOR})