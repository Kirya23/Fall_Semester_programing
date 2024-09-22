cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version") 
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH ${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

if (MSVC)
         set(CMAKE_CXX_FLAGS "/W4")
     else ()
         # Удалите -Werror, если он вам не нужен
         set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic") 
     endif()

target_compile_options(helloworld_cli PRIVATE ${CMAKE_CXX_FLAGS})
target_compile_options(helloworld PRIVATE ${CMAKE_CXX_FLAGS})
target_compile_options(test_version PRIVATE ${CMAKE_CXX_FLAGS})

# ... other CMake code ...

# Настройка CPack
set(CPACK_GENERATOR "ZIP" CACHE STRING "Package generator (ZIP, DEB, etc.)" FORCE)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
add_test(test_version test_version)

# Установка целевых объектов в директорию build/release
install(TARGETS helloworld_cli RUNTIME DESTINATION build/release/bin)
install(TARGETS helloworld RUNTIME DESTINATION build/release/lib)