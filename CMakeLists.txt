cmake_minimum_required(VERSION 3.17)

project(GameBoy__)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameBoy__ main.cpp Window.h DefaultShader.h Emulator/Emulator.cpp Emulator/Emulator.h GLContext.h)

target_link_libraries(GameBoy__ -lSDL2 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread -lGLEW)

 #SET(CMAKE_CXX_LINK_FLAGS -lGl -lSDL2 )

message(STATUS "<<${OPENGL_INCLUDE_DIRS}>>")
