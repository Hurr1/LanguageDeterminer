cmake_minimum_required(VERSION 3.16.3)
project(LanguageDeterminer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Algorithm)
add_subdirectory(Perceptron)
add_subdirectory(NeuralAlgorithm)

add_executable(LanguageDeterminer main.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC Perceptron)
target_link_directories(${PROJECT_NAME} PRIVATE Perceptron)
target_link_libraries(${PROJECT_NAME} Perceptron)


target_include_directories(${PROJECT_NAME} PUBLIC Algorithm)
target_link_directories(${PROJECT_NAME} PRIVATE Algorithm)
target_link_libraries(${PROJECT_NAME} Algorithm)

target_include_directories(${PROJECT_NAME} PUBLIC NeuralAlgorithm)
target_link_directories(${PROJECT_NAME} PRIVATE NeuralAlgorithm)
target_link_libraries(${PROJECT_NAME} NeuralAlgorithm)





