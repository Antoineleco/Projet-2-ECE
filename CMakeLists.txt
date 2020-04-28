cmake_minimum_required(VERSION 3.15)
project(Projet-2-ECE)

set(CMAKE_C_STANDARD 99)

add_executable(Projet-2-ECE main.c fonctions.c fonctions.h menutours.c menutours.h)
target_link_libraries(Projet-2-ECE -lmingw32 -lallegro-5.0.10-monolith-md-debug)