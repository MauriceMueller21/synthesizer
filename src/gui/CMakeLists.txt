cmake_minimum_required(VERSION 3.10)
project(test-gui LANGUAGES CXX)
find_package(Catch2 3 REQUIRED)
find_package(X11 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "*.cpp")
add_executable(test-gui ${SOURCE_FILES})
target_include_directories(test-gui PRIVATE .)
target_link_libraries(test-gui PRIVATE ${X11_LIBRARIES})
target_link_libraries(test-gui PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(test-gui --list-test-names-only)

