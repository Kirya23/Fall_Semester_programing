cmake_minimum_required(VERSION 3.10)
project(lab2 VERSION 0.1.0 LANGUAGES CXX)

# Настройка для Google Test
include(FindGTest)
if(gtest_FOUND)
 message(STATUS "Found GTest: ${gtest_INCLUDE_DIRS}")
 add_subdirectory(test)
endif()

# Основной исполняемый файл
add_executable(lab2 main.cpp)
target_link_libraries(lab2 test_ip_address)

# Настройка для сборки 
set(CMAKE_BUILD_TYPE Release) 
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install") 
add_custom_target( creat_package
COMMAND ${CMAKE_COMMAND} -E copy_directory bin "${CMAKE_INSTALL_PREFIX}/bin" 
 COMMAND ${CMAKE_COMMAND} -E copy_directory include "${CMAKE_INSTALL_PREFIX}/include" 
 COMMAND ${CMAKE_COMMAND} -E copy_directory lib "${CMAKE_INSTALL_PREFIX}/lib" 
 COMMAND ${CMAKE_COMMAND} -E copy_directory share "${CMAKE_INSTALL_PREFIX}/share" 
 COMMAND ${CMAKE_COMMAND} -E tar czf "${PROJECT_NAME}-${CMAKE_BUILD_TYPE}.tar.gz" "${CMAKE_INSTALL_PREFIX}" 
 COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_INSTALL_PREFIX}" 
) 

# Настройка тестов
include(CTest) 
enable_testing() 

# Настройка CPack 
set(CPACK_PROJECT_NAME ${PROJECT_NAME}) 
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION}) 
include(CPack)