/**
 *  @file    Renderer.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/27/2025
 **/

#include "graphics/renderer/Renderer.h"

#include "event/window/WindowEvent.h"

novum_engine::graphics::renderer::Renderer::Renderer(const platform::Platform& platform,
                                                     event::EventBus& eventBus) noexcept : m_event_bus(eventBus)
{
    m_graphics_backend = std::make_unique<backend::opengl::OpenGLBackend>(platform.getGraphicsContext());
    m_event_bus.subscribe<event::window::WindowResizedEvent>([this](event::window::WindowResizedEvent& event)
    {
        m_graphics_backend->resizeViewport(0, 0, event.width(), event.height());
        event.isHandled = true;
    });
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
