#include "utils.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

VertexArray::VertexArray() {
  GLCall(glGenVertexArrays(1, &id));
}

VertexArray::~VertexArray() {
  GLCall(glDeleteVertexArrays(1, &id));
}

void VertexArray::addBuffer(VertexBuffer& vb) {
  bind();
  vb.bind();
  // For the Vertex Buffer, maybe we want to 
  GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
  GLCall(glEnableVertexAttribArray(0));
}

void VertexArray::bind() const {
  GLCall(glBindVertexArray(id));
}

void VertexArray::unbind() const {
  GLCall(glBindVertexArray(0));
}
