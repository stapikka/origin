cmake_minimum_required(VERSION 3.22.0)
project(RacingGameCMake)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(RacingGame SHARED
 Vehicle.h
 GroundVehicle.h
 AirVehicle.h
 Camel.h
 FastCamel.h
 Centaur.h
 Boots.h
 Carpet.h
 Eagle.h
 Broom.h
 Race.h
 Vehicle.cpp
 GroundVehicle.cpp
 AirVehicle.cpp
 Camel.cpp
 FastCamel.cpp
 Centaur.cpp
 Boots.cpp
 Carpet.cpp
 Eagle.cpp
 Broom.cpp
 Race.cpp
)
add_executable(RacingGameExe main.cpp)
target_link_libraries(RacingGameExe RacingGame)