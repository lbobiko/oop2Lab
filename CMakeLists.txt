cmake_minimum_required(VERSION 4.0)
project(oop2Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop2Lab main.cpp
        Car.cpp
        Car.h
        Constants.h
        Engine.cpp
        Engine.h
        FuelTank.cpp
        FuelTank.h
        Brake.cpp
        Brake.h
        Dashboard.cpp
        Dashboard.h)
