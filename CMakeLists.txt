cmake_minimum_required(VERSION 3.10)

# Для создания переменных set
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

# имя проекта и его версия
project(helloworld VERSION ${PROJECT_VESRION})

# Поиск библиотеки
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# Создаёт файл versiona 
configure_file(version.h.in version.h)

# Добавляет  исполняемый  файл  helloworld_cli  с  использованием  файла  main.cpp. 
add_executable(helloworld_cli main.cpp)

#  Добавляет  статическую  библиотеку  helloworld  с  использованием  файла  lib.cpp. 
add_library(helloworld lib.cpp)

# ну тут и так понятно 
add_executable(test_version test_version.cpp)

# Устанавливает  свойства  для  таргетов  helloworld_cli,  helloworld  и  test_version:  стандарт  C++  (C++14)  и  требование  его  использования. 
set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Добавляет  в  путь  включения  заголовков  для  таргета  helloworld  путь  к  директории  со  сборкой  проекта  CMAKE_BINARY_DIR. 
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

# определяет  макрос  BOOST_TEST_DYN_LINK  для  динамической  связи  с  Boost  и  добавляет  в  путь  включения  заголовков  путь  Boost_INCLUDE_DIR. 
set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

# Связывает  helloworld_cli  с  библиотекой  helloworld. 
target_link_libraries(helloworld_cli PRIVATE
    helloworld
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

# Проверяет  компилятор  (MSVC  для  Visual  Studio).  Если  это  MSVC,  то  добавляет  флаги  компиляции  /W4  для  ошибок  компиляции.
# Иначе  добавляет  флаги  компиляции  -Wall -Wextra -pedantic -Werror  для  ошибок  компиляции. 
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

# Настройки для macOS: 😊 

# Установка минимальной версии macOS 😊 
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)   

# Определение архитектуры (ARM64 для Apple Silicon) 😊 
if(APPLE) 
    set(CMAKE_OSX_ARCHITECTURES arm64)  
    set(CMAKE_OSX_SYSROOT /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk)  
endif() 

# Установка исполняемого файла в директорию bin при установке 
install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
install(TARGETS helloworld ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Проверяет  режим  сборки (Сам написал 😁))   
if(CMAKE_BUILD_TYPE STREQUAL "Release") 
    set(CPACK_GENERATOR ZIP) 
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug") 
    set(CPACK_GENERATOR DEB)  
endif() 

# Устанавливает  параметры  пакета  для  CPack:  номер  версии  и  контактную  информацию.   
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}") 
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}") 
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}") 

set(CPACK_PACKAGE_CONTACT example@example.com) 
# Включает  модуль  CPack  для  создания  установочных  пакетов.   
include(CPack) 

#  Добавить  команду  упаковки  в  CMakeLists.txt
add_custom_target(create_package ALL  
    COMMAND ${CMAKE_COMMAND} -E tar cfz helloworld-${PROJECT_VESRION}-macOS.zip bin include lib 
    COMMAND ${CMAKE_COMMAND} -E message "Creating package helloworld-${PROJECT_VESRION}-macOS.zip")

# Включает  режим  тестирования  для  CMake.   
enable_testing()  
# Добавляет  тест  с  именем  test_version,  используя  исполняемый  файл  test_version.  
add_test(test_version test_version)