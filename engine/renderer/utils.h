#pragma once

#include <glad/gl.h>
#include <iostream>
#include <csignal>

// #define ASSERT(x) if (!(x)) __debugbreak();
#define ASSERT(x) if (!(x)) std::raise(SIGABRT);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));


struct color {
  float red;
  float green;
  float blue;
  float alpha;
};


struct point {
  float x;
  float y;
  float z;
};

// Clears all OpenGl errors
void GLClearError();

// Prints the OpenGL error to the console
bool GLLogCall(const char* function, const char* file, int line);
