#pragma once

class VertexArray {
 private:
  unsigned int id;

 public:
  VertexArray();
  ~VertexArray();
  void bind() const;
  void unbind() const;
}
