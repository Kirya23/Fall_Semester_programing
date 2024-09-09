cmake_minimum_required(VERSION 3.10)

# Определение версий
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

project(helloworld VERSION ${PROJECT_VERSION})

# Найти Boost
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# Создать файл version.h из version.h.in
configure_file(version.h.in version.h)

# Создать исполняемые файлы
add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version test_version.cpp)

# Задать свойства таргетов
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

# Связать зависимости
target_link_libraries(helloworld_cli PRIVATE
    helloworld
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

# Флаги компиляции
target_compile_options(helloworld_cli PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(helloworld PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(test_version PRIVATE -Wall -Wextra -pedantic -Werror)

# Установка
install(TARGETS helloworld_cli DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION include)

# Создание пакета
include(CPack)
set(CPACK_PACKAGE_NAME "helloworld")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
set(CPACK_GENERATOR ZIP)
include(CPack)

# Тесты
enable_testing()
add_test(test_version test_version)