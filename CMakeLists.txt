cmake_minimum_required(VERSION 3.10)

project(
  test-vcpkg-flint3
  VERSION 0.0.1
  LANGUAGES CXX)

find_package(PkgConfig REQUIRED)

add_executable(test1 main.cpp)
pkg_check_modules(flint REQUIRED IMPORTED_TARGET flint)
target_link_libraries(test1 PkgConfig::flint)

install(TARGETS test1 RUNTIME DESTINATION bin)
