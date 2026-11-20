#pragma once

class ElementBuffer {
 private:
  unsigned int id;
 public:
  ElementBuffer(const void* indices, unsigned int size);
  ~ElementBuffer();
  void bind() const;
  void unbind() const;
};
