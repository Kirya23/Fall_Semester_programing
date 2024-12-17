cmake_minimum_required(VERSION 3.10.0)
project(lab6 VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab6 main.cpp View.cpp controller.cpp model.cpp primitive.cpp)

include_directories(${CMAKE_SOURCE_DIR})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
