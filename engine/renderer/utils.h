#pragma once

#include <glad/gl.h>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
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
}

// Clears all OpenGl erros
void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

// Prints the OpenGL error to the console
bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): "<< function << " | " << file << ":" << line << '\n';
        return false;
    }
    return true;
}
