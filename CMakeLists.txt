# Imagine++ Libraries
# Copyright (C) Imagine
# For detailed information: http://imagine.enpc.fr/software

project(TestTDLOG)

cmake_minimum_required(VERSION 2.6)
find_package(Imagine REQUIRED)

add_executable(TestTDLOG main.cpp game.cpp Cannon.cpp Canvas.cpp Trooper.cpp Bullet.cpp Plane.cpp)
ImagineUseModules(TestTDLOG Graphics)

add_executable(TestTDLOG_tests test.cpp game.cpp Cannon.cpp Canvas.cpp Trooper.cpp Bullet.cpp Plane.cpp)
ImagineUseModules(TestTDLOG_tests Graphics)


