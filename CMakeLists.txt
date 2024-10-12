cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

# Find and include Google Test
include(FindGTest)
if(gtest_FOUND)
  message(STATUS "Found GTest: ${gtest_INCLUDE_DIRS}")
else()
  message(FATAL_ERROR "Google Test not found. Please install it.")
endif()

configure_file(version.h.in version.h)

# Add executables
add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version test_version.cpp)

# Set common target properties
set_target_properties(helloworld_cli helloworld test_version PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

# Include directories
target_include_directories(helloworld
  PRIVATE "${CMAKE_BINARY_DIR}"
)

# Link to Google Test
target_link_libraries(test_version
  gtest::gtest googletest::gtest_main 
  helloworld
)

# Link helloworld_cli 
target_link_libraries(helloworld_cli PRIVATE 
  helloworld
)

# Compiler flags
if (MSVC)
  target_compile_options(helloworld_cli PRIVATE
    /W4 
  )
  target_compile_options(helloworld PRIVATE 
    /W4 
  )
  target_compile_options(test_version PRIVATE 
    /W4 
  )
else ()
  target_compile_options(helloworld_cli PRIVATE 
    -Wall -Wextra -pedantic -Werror 
  )
  target_compile_options(helloworld PRIVATE 
    -Wall -Wextra -pedantic -Werror 
  )
  target_compile_options(test_version PRIVATE 
    -Wall -Wextra -pedantic -Werror 
  )
endif()

# Install
install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

# CPack
# Установка пакета DEB для Linux
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(CPACK_GENERATOR DEB) 
endif()

# Установка пакета ZIP для macOS
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CPACK_GENERATOR ZIP)
endif()

include(CPack)
