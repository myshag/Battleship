cmake_minimum_required(VERSION 3.0.0)
project(battleship VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)
set( CMAKE_LIBRARY_PATH "/usr/lib64/libncurses.so.6")
set( CMAKE_INCLUDE_PATH "/usr/include")


include(CTest)
enable_testing()

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#file(GLOB TARGET_SRC
#     "*.h"
#     "*.cpp"
#)



SET(TARGET_SRC
    Models/BoardModel.h
    Observer/Observer.cpp
    BoardView.cpp
    Models/BoardModel.cpp
    main.cpp
    )

add_executable(battleship ${TARGET_SRC})
target_link_libraries(battleship ${CURSES_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
