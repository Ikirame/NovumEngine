/**
 *  @file    Application.inl
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/12/2025
 **/

#ifndef NOVUM_ENGINE_APPLICATION_INLINE_H
#define NOVUM_ENGINE_APPLICATION_INLINE_H

#include "Application.h"
#include "platform/Platform.h"

namespace novum_engine::core
{
    template <typename Derived>
    Application<Derived>::Application() noexcept
    {
        m_window = m_platform.createWindow(m_event_dispatcher);
        m_graphics_renderer = std::make_unique<graphics::renderer::Renderer>(m_platform.createGraphicsBackend());

        m_event_dispatcher.subscribe(event::EventType::WindowClose, [this](const event::Event&)
        {
            m_is_running = false;
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
            m_platform.pollEvents();

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
