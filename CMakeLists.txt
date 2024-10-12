cmake_minimum_required(VERSION 3.10)
  project(lab2 VERSION 0.1.0 LANGUAGES CXX)

  # Укажите путь к Google Test
  set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/path/to/gtest/installation" CACHE STRING "Path to Google Test installation")

  # Найдите и включите Google Test
  include(FindGTest)
  if(gtest_FOUND)
    message(STATUS "Found GTest: ${gtest_INCLUDE_DIRS}")
    add_subdirectory(test)
  else()
  endif()

# Main executable
add_executable(lab2 main.cpp)
target_link_libraries(lab2 googletest) 

# Build configuration
set(CMAKE_BUILD_TYPE Release) 
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install") 

# Custom target for packaging (optional)
add_custom_target(create_package
  COMMAND ${CMAKE_COMMAND} -E copy_directory bin "${CMAKE_INSTALL_PREFIX}/bin"
  COMMAND ${CMAKE_COMMAND} -E copy_directory include "${CMAKE_INSTALL_PREFIX}/include"
  COMMAND ${CMAKE_COMMAND} -E copy_directory lib "${CMAKE_INSTALL_PREFIX}/lib"
  COMMAND ${CMAKE_COMMAND} -E copy_directory share "${CMAKE_INSTALL_PREFIX}/share"
  COMMAND ${CMAKE_COMMAND} -E tar czf "${PROJECT_NAME}-${CMAKE_BUILD_TYPE}.tar.gz" "${CMAKE_INSTALL_PREFIX}"
  COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_INSTALL_PREFIX}"
)

# Test configuration (already good)
include(CTest) 
enable_testing() 

# CPack configuration (already good)
set(CPACK_PROJECT_NAME ${PROJECT_NAME}) 
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION}) 
include(CPack)