
cmake_minimum_required(VERSION 3.10)

project(bitVector VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# библиотека
add_library(bitVector SHARED
    src/bitVector.c
)

# заголовки
target_include_directories(bitVector
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# версия библиотеки
set_target_properties(bitVector PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# тесты
add_executable(test_bitVector
    tests/test_bitVector.c
)

target_link_libraries(test_bitVector
    PRIVATE bitVector
)
