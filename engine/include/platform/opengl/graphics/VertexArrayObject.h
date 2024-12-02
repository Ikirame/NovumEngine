/**
 *  @file    VertexArrayObject.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/22/2022
 **/

#ifndef NOVUM_ENGINE_OPENGL_VERTEX_ARRAY_OBJECT_H
#define NOVUM_ENGINE_OPENGL_VERTEX_ARRAY_OBJECT_H

#include <glad/gl.h>

namespace novum_engine::platform::opengl::graphics
{
    class VertexArrayObject
    {
    public:
        explicit VertexArrayObject() noexcept;

        VertexArrayObject(VertexArrayObject const& rhs) noexcept = delete;
        VertexArrayObject(VertexArrayObject&& rhs) noexcept = delete;

        VertexArrayObject& operator=(VertexArrayObject const& rhs) noexcept = delete;
        VertexArrayObject& operator=(VertexArrayObject&& rhs) noexcept = delete;

        ~VertexArrayObject() noexcept;

        void bind() const noexcept;
        static void unbind() noexcept;

    private:
        GLuint m_buffer;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_VERTEX_ARRAY_OBJECT_H */
