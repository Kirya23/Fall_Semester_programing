cmake_minimum_required(VERSION 3.5.0)
project(lab6 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lab6 main.cpp Document.cpp Circle.cpp Line.cpp Shape.cpp View.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
