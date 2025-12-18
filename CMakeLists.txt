cmake_minimum_required(VERSION 3.16)
project(lomolab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)

add_executable(lomolab
    src/main.cpp
    src/ui.cpp
    src/renderer.cpp
    src/filters.cpp
)

target_include_directories(lomolab PRIVATE
    ${CURSES_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(lomolab PRIVATE
    ${CURSES_LIBRARIES}
    ${OpenCV_LIBS}
)

