#pragma once

#include "ElementBuffer.h"
#include "VertexArray.h"

class Renderer {

private:

public:
    void Clear() const;
    void Draw(VertexArray& va, ElementBuffer& eb) const;
};
