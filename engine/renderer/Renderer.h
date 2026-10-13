#pragma once

// #include "ElementBuffer.h"
#include "VertexArray.h"

class Renderer {

private:

public:
    void clear() const;
    void draw(VertexArray& va) const;
};
