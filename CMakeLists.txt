cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version") 
set(PROJECT_VESRION 0.0.${PATCH_VERSION}) 

project(lab2 VERSION ${PROJECT_VESRION}) 

# ... (Если Google Test не в стандартном месте)
# set(gtest_DIR "/путь/к/установке/gtest") 

include(FindGTest) 
if(gtest_FOUND) 
 message(STATUS "Found GTest: ${gtest_INCLUDE_DIRS}") 
endif() 

# Add executables 
add_executable(lab2_cli main.cpp) 
add_library(lab2 test_ip_address.cpp) 

# Set common target properties 
set_target_properties(lab2 PROPERTIES 
 CXX_STANDARD 14 
 CXX_STANDARD_REQUIRED ON 
) 

# Include directories 
target_include_directories(lab2 
 PRIVATE "${CMAKE_BINARY_DIR}" 
) 

# Link to Google Test
target_link_libraries(lab2 
 PRIVATE gtest::gtest googletest::gtest_main 
) 

# Link lab2_cli 
target_link_libraries(lab2_cli 
 PRIVATE lab2 
) 

# Compiler flags 
if (MSVC) 
 target_compile_options(lab2_cli PRIVATE 
  /W4 
 ) 
 target_compile_options(lab2 PRIVATE 
  /W4 
 ) 
 target_compile_options(test_lab2 PRIVATE 
  /W4 
 ) 
else () 
 target_compile_options(lab2_cli PRIVATE 
  -Wall -Wextra -pedantic -Werror 
 ) 
 target_compile_options(lab2 PRIVATE 
  -Wall -Wextra -pedantic -Werror 
 ) 
 target_compile_options(lab2 PRIVATE 
  -Wall -Wextra -pedantic -Werror 
 ) 
endif() 

# Install 
install(TARGETS lab2_cli RUNTIME DESTINATION bin) 

# CPack 
# Установка пакета DEB для Linux 
if (CMAKE_SYSTEM_NAME STREQUAL "Linux") 
 set(CPACK_GENERATOR DEB) 
endif() 

# Установка пакета ZIP для macOS 
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin") 
 set(CPACK_GENERATOR ZIP) 
endif() 

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}") 
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}") 
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}") 

set(CPACK_PACKAGE_CONTACT example@example.com) 

include(CPack) 

# Настройка тестов 
enable_testing() 
add_test(test_lab2 test_lab2)