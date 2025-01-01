/**
 *  @file    Application.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

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
        graphics::api::opengl::OpenglGraphicsApi::render();

        onUpdate();
        m_window->onUpdate();
    }
}

void onWindowClosed() noexcept;
