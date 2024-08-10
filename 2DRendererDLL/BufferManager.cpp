#include "BufferManager.h"

namespace Renderer {
    BufferManager::BufferManager(Grid& grid) : grid(grid) {
        glGenVertexArrays(1, &grid.GetVAO());
        glGenBuffers(1, &grid.GetVBO());
    }

    BufferManager::~BufferManager() {
        glDeleteVertexArrays(1, &grid.GetVAO());
        glDeleteBuffers(1, &grid.GetVBO());
    }

    void BufferManager::Bind() {
        glBindVertexArray(grid.GetVAO());
        glBindBuffer(GL_ARRAY_BUFFER, grid.GetVBO());
    }

    void BufferManager::Unbind() const {
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void BufferManager::SetBufferData(size_t size, const void* data, GLenum usage) const {
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    void BufferManager::SetVertexAttribPointer(unsigned int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        glEnableVertexAttribArray(index);
    }
}