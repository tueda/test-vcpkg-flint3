cmake_minimum_required(VERSION 3.10)

project(
  test-vcpkg-flint3
  VERSION 0.0.1
  LANGUAGES C CXX)

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} -Wl,--no-as-needed"
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(gmp REQUIRED IMPORTED_TARGET gmp)
pkg_check_modules(mpfr REQUIRED IMPORTED_TARGET mpfr)
pkg_check_modules(flint REQUIRED IMPORTED_TARGET flint)

add_executable(test test.c)
target_link_libraries(test
  PRIVATE
    PkgConfig::flint
    PkgConfig::gmp
    PkgConfig::mpfr
    m
)

# add_executable(test1 main.cpp)
# target_link_libraries(test1 PkgConfig::flint)

# install(TARGETS test1 RUNTIME DESTINATION bin)
