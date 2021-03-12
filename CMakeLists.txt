cmake_minimum_required(VERSION 3.0.0)
project(battleship VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()


SET(TARGET_SRC
    Observer.cpp
    BoardView.cpp
    )

add_executable(battleship main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
