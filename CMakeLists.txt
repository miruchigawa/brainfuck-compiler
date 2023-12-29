cmake_minimum_required(VERSION 3.22)

project(brainfuck)

file(GLOB executable *.cpp)

add_executable(${PROJECT_NAME} ${executable})