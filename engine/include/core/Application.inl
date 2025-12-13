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
        m_window = platform::Platform::getInstance().createWindow();
        m_window->subscribe(event::window::WindowEventType::Closed, BIND_EVENT_FN(Application::onWindowClosed));

        const auto& self = static_cast<Derived&>(*this);
        self.onInit();
    }

    template <typename Derived>
    void Application<Derived>::run() const noexcept
    {
        const auto& self = static_cast<const Derived&>(*this);
        while (m_is_running)
        {
            self.onUpdate();
            m_window->update();

            platform::Platform::getInstance().pollEvents();
            graphics::api::opengl::OpenglGraphicsApi::render();
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
