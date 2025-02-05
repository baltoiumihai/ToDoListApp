cmake_minimum_required(VERSION 3.30)
project(ToDoListApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ToDoListApp src/main.cpp src/Task.cpp src/ToDoList.cpp
        src/Task.cpp
        src/Task.h
        src/ToDoList.cpp
        src/ToDoList.h
        src/Priority.cpp
        src/Priority.h)
