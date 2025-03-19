cmake_minimum_required(VERSION 3.22.0)

project(classes_figures)

set (SOURCES
 source.cpp
 Figure.cpp
 Triangle.cpp
 EquilateralTriangle.cpp
 IsoscelesTriangle.cpp
 Parallelogram.cpp
 Quadrangle.cpp
 Rhombus.cpp
 RightTriangle.cpp
 Square.cpp
)

set (HEADERS
 Figure.h
 Triangle.h
 EquilateralTriangle.h
 IsoscelesTriangle.h
 Parallelogram.h
 Quadrangle.h
 Rhombus.h
 RightTriangle.h
 Square.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})