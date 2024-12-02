/**
 *  @file    VertexBufferObject.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/22/2022
 **/

#ifndef NOVUM_ENGINE_OPENGL_VERTEX_BUFFER_OBJECT_H
#define NOVUM_ENGINE_OPENGL_VERTEX_BUFFER_OBJECT_H

namespace novum_engine::platform::opengl::graphics
{
    class VertexBufferObject
    {
    public:
        explicit VertexBufferObject(GLsizeiptr size, const GLvoid* data) noexcept;

        VertexBufferObject(VertexBufferObject const& rhs) noexcept = delete;
        VertexBufferObject(VertexBufferObject&& rhs) noexcept = delete;

        VertexBufferObject& operator=(VertexBufferObject const& rhs) noexcept = delete;
        VertexBufferObject& operator=(VertexBufferObject&& rhs) noexcept = delete;

        ~VertexBufferObject() noexcept;

        void bind() noexcept;

        static void unbind() noexcept;

    private:
        GLuint m_buffer;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_VERTEX_BUFFER_OBJECT_H */
