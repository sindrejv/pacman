cmake_minimum_required(VERSION 3.15)
project(pacman_exam)

set(CMAKE_CXX_STANDARD 17)

add_executable(pacman_exam main.cpp InputManager.cpp InputManager.h GameManager.cpp GameManager.h Tile.cpp Tile.h Pacman.cpp Pacman.h Image.cpp Image.h Ghost.cpp Ghost.h Pills.cpp Pills.h GameMenu.cpp GameMenu.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${pacman_exam_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(pacman_exam ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
