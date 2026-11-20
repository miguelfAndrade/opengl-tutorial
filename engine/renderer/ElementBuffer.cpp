#include "utils.h"
#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(const void* indices, unsigned int size) {
  GLCall(glGenBuffers(1, &id))
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
  GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW));
}

ElementBuffer::~ElementBuffer() {
  GLCall(glDeleteBuffers(1, &id));
}

void ElementBuffer::bind() const {
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
}

void ElementBuffer::unbind() const {
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
