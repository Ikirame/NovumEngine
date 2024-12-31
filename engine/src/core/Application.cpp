/**
 *  @file    Application.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include <glad/gl.h>

#include "Application.h"

#include "event/window/WindowEventType.h"

novum_engine::core::Application::Application() noexcept
{
    m_window->subscribe(event::window::WindowEventType::Closed, BIND_EVENT_FN(Application::onWindowClosed));
}

void novum_engine::core::Application::run() const noexcept
{
    while (m_is_running)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        onUpdate();
        m_window->onUpdate();
    }
}

void onWindowClosed() noexcept;
