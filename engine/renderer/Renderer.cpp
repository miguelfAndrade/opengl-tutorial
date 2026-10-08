#include "utils.h"
#include "Renderer.h"

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
}

void Renderer::Draw(VertexArray& va, ElementBuffer& eb) const {
    va.bind();
    eb.bind();
    GLCall(glDrawElements(GL_TRIANGLES, eb.getCount(), GL_UNSIGNED_INT, nullptr));
    // GLCall(glDrawElements(GL_TRIANGLES, sizeof(squareIndices) / sizeof(unsigned int), GL_UNSIGNED_INT, nullptr));
}
