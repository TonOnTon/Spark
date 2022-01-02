cmake_minimum_required(VERSION 3.18.4)

project(Spark)

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

add_subdirectory(src/Game)
