#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
 

class Game {
 private:
  GLFWwindow* window;
  // std::vector<Scene> scenes; Can be levels
  // Scene -> std::vector<Object> objects
  // class Shape: public Object
  
 public:
  Game(int width, int height, const char* title);
  ~Game();

  int start();
};
