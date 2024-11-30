/**
 *  @file    VertexArrayObject.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/22/2024
 **/

#include "platform/opengl/graphics/VertexArrayObject.h"

novum_engine::platform::opengl::graphics::VertexArrayObject::VertexArrayObject() noexcept : m_buffer()
{
    glGenVertexArrays(1, &m_buffer);
    bind();
}

novum_engine::platform::opengl::graphics::VertexArrayObject::~VertexArrayObject() noexcept
{
    glDeleteVertexArrays(1, &m_buffer);
}

void novum_engine::platform::opengl::graphics::VertexArrayObject::bind() const noexcept
{
    glBindVertexArray(m_buffer);
}

void novum_engine::platform::opengl::graphics::VertexArrayObject::unbind() noexcept
{
    glBindVertexArray(0);
}
