cmake_minimum_required(VERSION 3.22.0)
project(FiguresLibraryCMake)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FiguresLibrary SHARED
 Figure.h
 Triangle.h
 RightTriangle.h
 Figure.cpp
 Triangle.cpp
 RightTriangle.cpp
)
add_executable(FigureClientExe FigureClient.cpp)
target_link_libraries(FigureClientExe FiguresLibrary)