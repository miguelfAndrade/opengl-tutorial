#pragma once

#include "VertexBuffer.h"

class VertexArray {
 private:
  unsigned int id;

 public:
  VertexArray();
  ~VertexArray();

  void addVertexBuffer(const VertexBuffer& vb);
  void bind() const;
  void unbind() const;
}
