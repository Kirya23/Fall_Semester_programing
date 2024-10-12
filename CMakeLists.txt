cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(lab2 VERSION ${PROJECT_VESRION})

# Находим Google Test
find_package(GTest REQUIRED)

# Включаем FindGTest
include(FindGTest) 
if(gtest_FOUND) 
 message(STATUS "Found GTest: ${gtest_INCLUDE_DIRS}")
endif() 

# Добавляем библиотеку lab2
add_library(lab2 test_ip_address.cpp) 

# Добавляем исполняемый файл lab2_cli
add_executable(lab2_cli main.cpp)

# Добавляем тестовый исполняемый файл
add_executable(test_ip_address test_ip_address.cpp)

# Устанавливаем общие свойства для lab2
set_target_properties(lab2 PROPERTIES 
 CXX_STANDARD 14 
 CXX_STANDARD_REQUIRED ON 
)

# Включаем директории для lab2
target_include_directories(lab2 
 PRIVATE "${CMAKE_BINARY_DIR}" 
)

# Связываем lab2_cli с lab2
target_link_libraries(lab2_cli 
 PRIVATE lab2 
)

# Флаги компилятора
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
 target_compile_options(test_ip_address PRIVATE 
  /W4 
 )
else ()
 target_compile_options(lab2_cli PRIVATE 
  -Wall -Wextra -pedantic -Werror 
 )
 target_compile_options(lab2 PRIVATE 
  -Wall -Wextra -pedantic -Werror 
 )

 target_compile_options(test_ip_address PRIVATE 
  -Wall -Wextra -pedantic -Werror 
 )
endif()

# Установка
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
add_test(test_lab2 test_ip_address) 