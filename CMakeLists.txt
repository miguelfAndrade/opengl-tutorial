cmake_minimum_required(VERSION 3.16)
project(MyOpenGLApp LANGUAGES C CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
 
add_library(glad STATIC glad/src/gl.c)
target_include_directories(glad PUBLIC glad/include)
 
add_executable(myapp src/main.cpp src/game.cpp)
target_link_libraries(myapp PRIVATE glad OpenGL::GL glfw)
