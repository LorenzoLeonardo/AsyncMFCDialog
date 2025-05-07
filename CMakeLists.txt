cmake_minimum_required(VERSION 3.15)
project(AsyncMFCDialog LANGUAGES CXX)

# Header-only library
add_library(AsyncMFCDialog INTERFACE)

# Require C++20
target_compile_features(AsyncMFCDialog INTERFACE cxx_std_20)

add_definitions(-D_WIN32_WINNT=0x0A00)  # 0x0A00 corresponds to Windows 10 and Windows 11

# Include path
target_include_directories(AsyncMFCDialog INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Install headers
install(DIRECTORY include/ DESTINATION include)

# Export the target
install(TARGETS AsyncMFCDialog
    EXPORT AsyncMFCDialogTargets
    INCLUDES DESTINATION include
)

# Generate and install CMake package config
install(EXPORT AsyncMFCDialogTargets
    FILE AsyncMFCDialogTargets.cmake
    NAMESPACE AsyncMFCDialog::
    DESTINATION lib/cmake/AsyncMFCDialog
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/AsyncMFCDialogConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/AsyncMFCDialogConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/AsyncMFCDialogConfig.cmake"
    INSTALL_DESTINATION lib/cmake/AsyncMFCDialog
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/AsyncMFCDialogConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/AsyncMFCDialogConfigVersion.cmake"
    DESTINATION lib/cmake/AsyncMFCDialog
)

# Add subdirectory for tests
add_subdirectory(test)