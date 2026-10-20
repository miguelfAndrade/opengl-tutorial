cmake_minimum_required(VERSION 3.16)
project(EngineGL LANGUAGES C CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
 
add_library(engine OBJECT
  glad/src/gl.c
  renderer/Renderer.cpp
  renderer/VertexArray.cpp
  renderer/VertexBuffer.cpp
  renderer/utils.cpp
  src/Game.cpp
)

target_include_directories(engine PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
  ${CMAKE_CURRENT_SOURCE_DIR}/renderer
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add_library(renderer STATIC renderer/Renderer.cpp renderer/VertexArray.cpp renderer/VertexBuffer.cpp renderer/utils.cpp)
# target_include_directories(renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/renderer)

# add_library(engine STATIC src/Game.cpp)
# target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# target_link_libraries(renderer PUBLIC glad OpenGL::GL glfw)
# target_link_libraries(engine PUBLIC renderer)
target_link_libraries(engine PUBLIC OpenGL::GL glfw)
