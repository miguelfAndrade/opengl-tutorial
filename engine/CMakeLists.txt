cmake_minimum_required(VERSION 3.16)
project(EngineGL LANGUAGES C CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
 
add_library(glad STATIC glad/src/gl.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)

add_library(engine STATIC src/game.cpp)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(engine PUBLIC glad OpenGL::GL glfw)
