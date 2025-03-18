cmake_minimum_required(VERSION 3.22.0)
project(classes_figures)
add_executable(classes_figures_programm source.cpp Figure.h Figure.cpp
Triangle.h Triangle.cpp EquilateralTriangle.h EquilateralTriangle.cpp
IsoscelesTriangle.h IsoscelesTriangle.cpp Parallelogram.h Parallelogram.cpp
Quadrangle.h Quadrangle.cpp Rhombus.h Rhombus.cpp RightTriangle.h RightTriangle.cpp
Square.h Square.cpp)