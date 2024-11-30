/**
 *  @file    VertexBufferObject.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/22/2024
 **/

#include "platform/opengl/graphics/VertexBufferObject.h"

novum_engine::platform::opengl::graphics::VertexBufferObject::VertexBufferObject(const GLsizeiptr size, const GLvoid* data) noexcept : m_buffer()
{
    glGenBuffers(1, &m_buffer);

    glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

novum_engine::platform::opengl::graphics::VertexBufferObject::~VertexBufferObject() noexcept
{
    glDeleteBuffers(1, &m_buffer);
}

void novum_engine::platform::opengl::graphics::VertexBufferObject::unbind() noexcept
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
