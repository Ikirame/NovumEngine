/**
 *  @file    OpenGLBackend.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#ifndef NOVUM_ENGINE_OPENGL_BACKEND_H
#define NOVUM_ENGINE_OPENGL_BACKEND_H

namespace novum_engine::graphics::backend::opengl
{
    typedef void (*OpenGLApiProc)();
    typedef OpenGLApiProc (*OpenGLLoadFunc)(const char *name);

    class OpenGLBackend
    {
    public:
        explicit OpenGLBackend(const OpenGLLoadFunc& glLoadFunc) noexcept;

        OpenGLBackend(OpenGLBackend const& rhs) noexcept = delete;
        OpenGLBackend(OpenGLBackend&& rhs) noexcept = delete;

        OpenGLBackend& operator=(OpenGLBackend const& rhs) noexcept = delete;
        OpenGLBackend& operator=(OpenGLBackend&& rhs) noexcept = delete;

        void beginFrame() const noexcept;
        void draw() const noexcept;
        void endFrame() const noexcept;

        void resizeViewport(int x, int y, int width, int height) const noexcept;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_BACKEND_H */
