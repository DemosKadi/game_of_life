cmake_minimum_required(VERSION 3.14)

project(game_of_life LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing(true)

find_package(Qt5 COMPONENTS Core Test REQUIRED)

set(EXE game_of_life)
add_executable(${EXE})

target_sources(${EXE}
    PRIVATE main.cpp
    PRIVATE input_parser.cpp
    PRIVATE game.cpp
    PRIVATE field.cpp
)

target_link_libraries(${EXE} Qt5::Core)

set(TESTS tests)
add_executable(${TESTS})
target_sources(${TESTS}
    PRIVATE tests.cpp
    PRIVATE input_parser.cpp
    PRIVATE field.cpp
)
add_test(NAME ${TESTS} COMMAND tests)

target_link_libraries(${TESTS}
    PRIVATE Qt5::Test
)
