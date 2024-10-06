cmake_minimum_required(VERSION 3.5.0)
project(lab2 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lab2 main.cpp)

include(CTest)
enable_testing()

include(FindGTest)
    if(gtest_FOUND)
     message(STATUS "Found GTest: ${gtest_INCLUDE_DIRS}")
     add_subdirectory(test)
    endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
