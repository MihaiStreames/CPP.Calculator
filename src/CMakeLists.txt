cmake_minimum_required(VERSION 3.24)
project(Calculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(Calculator
        calculator.cpp
        calculator.h
        ops/arithmetics.cpp
        ops/operations.h
        ops/negation.cpp
        expr-proc.cpp
        expr-proc.h
        tests.cpp)