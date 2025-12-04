# 文件 src/resource/CMakeLists.txt

add_executable(test_res MACOSX_BUNDLE main.cpp content.txt)

set_source_files_properties(content.txt PROPERTIES MACOSX_PACKAGE_LOCATION Other)

set_target_properties(test_res PROPERTIES OUTPUT_NAME TestRes)

install(TARGETS test_res DESTINATION ${CMAKE_HOST_SYSTEM_PROCESSOR})