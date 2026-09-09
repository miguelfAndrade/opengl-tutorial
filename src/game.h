#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
 

class Game {
 private:
  GLFWwindow* window;

 public:
  Game(int width, int height, const char* title);
  ~Game();

  int start();
};
