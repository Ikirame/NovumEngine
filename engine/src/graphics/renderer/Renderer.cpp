/**
 *  @file    Renderer.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/27/2025
 **/

#include "graphics/renderer/Renderer.h"

novum_engine::graphics::renderer::Renderer::Renderer(
    std::unique_ptr<backend::opengl::OpenGLBackend> graphicsBackend) noexcept
{
    m_graphics_backend = std::move(graphicsBackend);
}

void novum_engine::graphics::renderer::Renderer::beginFrame() const noexcept
{
    m_graphics_backend->beginFrame();
}

void novum_engine::graphics::renderer::Renderer::render() const noexcept
{
    m_graphics_backend->draw();
}

void novum_engine::graphics::renderer::Renderer::endFrame() const noexcept
{
    m_graphics_backend->endFrame();
}
