#include "Game.h"

Game::Game(int width, int height, const char* title) {
  if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
  }

  // Setting some properties to the new window that I want to create
  // Some tutorials use OpenGL 3.3 as default, this means minimum version
  // From v3.2 it was introduced two profiles, CORE and COMPATIBILITY
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 

  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!window) {
        std::cerr << "Failed to create an OpenGL 3.3 window\n";
        glfwTerminate();
        return;
  }

    // We need to specifically tell that we want the current OpenGL context
    // We are using GLAD as our loader library that enables us to OpenGL extensions
    glfwMakeContextCurrent(window);
    if (!gladLoadGL(glfwGetProcAddress)) {
        std::cerr << "Failed to load OpenGL functions\n";
        glfwTerminate();
        return;
    }
}

Game::~Game() {
  // glDeleteVertexArrays(1, &VAO);
  // glDeleteBuffers(1, &VBO);
  // glDeleteProgram(shaderProgram);
  glfwTerminate();
}

int Game::start() {

const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
void main() {
    gl_Position = vec4(aPos, 1.0);
}
)";
 
const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
)";

  // Variable to store the widht and height of the window
  int framebufferWidth, framebufferHeight;
  glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
  // Sets the actual viewport with the height and width of the window.
  glViewport(0, 0, framebufferWidth, framebufferHeight);

  // Triangle vertices
  // Take into account that the coordinates are normalized
  // Normalized Device Coordinates (NDC)
  float vertices[] = {
      -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
       0.0f,  0.5f, 0.0f
  };

  // VAO (Vertex Array Object)
  // VBO (Vetex Buffer Object)
  unsigned int VAO, VBO;
  // Create VAO (Vertex Array Object) object and store the ID
  glGenVertexArrays(1, &VAO);
  // Tells to OpenGL to activate this VAO (This VAO will be used to store the next configurations)
  glBindVertexArray(VAO);
  // Create VBO (Vertex Buffer Object) object and store the ID
  glGenBuffers(1, &VBO);
  // Binds the GL_ARRAY_BUFFER target to the VBO ID
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // Upload the data to the defined target, which is bound to the previouly created vertex buffer object
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // Tells OpenGL how to interpret the data
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);
 
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);
 
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);
 
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
 
  while (!glfwWindowShouldClose(window)) {
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glUseProgram(shaderProgram);
      glBindVertexArray(VAO);
      glDrawArrays(GL_TRIANGLES, 0, 3);
      glfwSwapBuffers(window);
      glfwPollEvents();
  }
 
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);

  return 0;
}
