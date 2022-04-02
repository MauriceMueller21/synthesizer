cmake_minimum_required(VERSION 3.10)
project(test-graphics LANGUAGES CXX)
find_package(Catch2 3 REQUIRED)

add_executable(test-graphics tests/example.cpp)
target_link_libraries(test-graphics PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(test-graphics --list-test-names-only)

