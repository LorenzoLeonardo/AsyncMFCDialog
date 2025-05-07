# test/CMakeLists.txt

# Add the test executable
add_executable(test_async_mfc_dialog test.cpp)

# Link the AsyncMFCDialog INTERFACE library
target_link_libraries(test_async_mfc_dialog PRIVATE AsyncMFCDialog)

# Enable MFC support for Visual Studio projects
if (MSVC)
    target_compile_definitions(test_async_mfc_dialog PRIVATE _AFXDLL)  # MFC DLL
    target_compile_options(test_async_mfc_dialog PRIVATE /D_MBCS)  # Multi-byte support for MFC
endif()