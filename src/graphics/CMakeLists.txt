cmake_minimum_required(VERSION 3.10)
project(graphics LANGUAGES CXX)
find_package(Catch2 3 REQUIRED)

add_executable(tests tests/example.cpp)


target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests --list-test-names-only)

