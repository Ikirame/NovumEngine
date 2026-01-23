/**
 *  @file    Application.inl
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/12/2025
 **/

#ifndef NOVUM_ENGINE_APPLICATION_INLINE_H
#define NOVUM_ENGINE_APPLICATION_INLINE_H

#include "Application.h"
#include "event/window/WindowEvent.h"
#include "platform/Platform.h"

namespace novum_engine::core
{
    template <typename Derived>
    Application<Derived>::Application() noexcept
    {
        m_platform = std::make_unique<platform::Platform>(graphics::GraphicsBackend::OpenGL, m_event_dispatcher);
        m_window = m_platform->createWindow("NovumEngine", 800, 600);

        m_graphics_renderer = std::make_unique<graphics::renderer::Renderer>(*m_platform, m_event_dispatcher);
        m_input_system = std::make_unique<input::InputSystem>(*m_window);

        m_event_dispatcher.subscribe<event::window::WindowClosedEvent>([this](event::window::WindowClosedEvent& event)
        {
            m_is_running = false;
            event.isHandled = true;
        });

        const auto& self = static_cast<Derived&>(*this);
        self.onInit();
    }

    template <typename Derived>
    void Application<Derived>::run() const noexcept
    {
        const auto& self = static_cast<const Derived&>(*this);
        while (m_is_running)
        {
            m_platform->pollEvents();
            m_input_system->update();

            self.onUpdate();

            m_graphics_renderer->beginFrame();
            self.onUpdateUI();
            m_graphics_renderer->render();
            m_graphics_renderer->endFrame();

            m_window->swapBuffers();
        }
    }

    template <typename Derived>
    Application<Derived>::~Application() noexcept
    {
        const auto& self = static_cast<Derived&>(*this);
        self.onDestroy();
    }
}

#endif /* NOVUM_ENGINE_APPLICATION_INLINE_H */
