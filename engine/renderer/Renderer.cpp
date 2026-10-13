#include "utils.h"
#include "Renderer.h"

void Renderer::clear() const {
    // GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::draw(VertexArray& va) const {
    va.bind();
    // eb.bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
    // GLCall(glDrawElements(GL_TRIANGLES, eb.getCount(), GL_UNSIGNED_INT, nullptr));
}
