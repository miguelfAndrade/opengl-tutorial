cmake_minimum_required(VERSION 3.16)
project(MyOpenGLApp LANGUAGES C CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(engine)

# add_library(engine STATIC ${CMAKE_CURRENT_LIST_DIR}/engine)
# target_include_directories(engine PRIVATE ${CMAKE_CURRENT_LIST_DIR}/engine)

add_executable(myapp src/main.cpp)
# target_link_libraries(myapp PRIVATE glad OpenGL::GL glfw engine)
target_link_libraries(myapp PRIVATE engine)
