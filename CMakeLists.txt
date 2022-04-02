cmake_minimum_required(VERSION 3.21)
project(LanguageDeterminer)

set(CMAKE_CXX_STANDARD 17)

add_executable(LanguageDeterminer "Source /main.cpp" "Source /Perceptron.cpp" Header/Perceptron.h "Source /Algorithm.cpp" Header/Algorithm.h)
