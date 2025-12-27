/**
 *  @file    Renderer.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/27/2025
 **/

#ifndef NOVUM_ENGINE_RENDERER_H
#define NOVUM_ENGINE_RENDERER_H

#include <memory>

#include "graphics/backend/opengl/OpenGLBackend.h"

namespace novum_engine::graphics::renderer
{
    class Renderer
    {
    public:
        explicit Renderer(std::unique_ptr<backend::opengl::OpenGLBackend> graphicsBackend) noexcept;

        Renderer(Renderer const& rhs) noexcept = delete;
        Renderer(Renderer&& rhs) noexcept = delete;

        Renderer& operator=(Renderer const& rhs) noexcept = delete;
        Renderer& operator=(Renderer&& rhs) noexcept = delete;

        void beginFrame() const noexcept;
        void render() const noexcept;
        void endFrame() const noexcept;

    private:
        std::unique_ptr<backend::opengl::OpenGLBackend> m_graphics_backend;
    };
}

#endif /* NOVUM_ENGINE_RENDERER_H */
