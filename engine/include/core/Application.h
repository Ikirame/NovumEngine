/**
 *  @file    Application.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_APPLICATION_H
#define NOVUM_ENGINE_APPLICATION_H

#include "graphics/renderer/Renderer.h"
#include "platform/Platform.h"
#include "platform/Window.h"

namespace novum_engine::core
{
    template <typename Derived>
    class Application
    {
    public:
        Application(Application const& rhs) noexcept = delete;
        Application(Application&& rhs) noexcept = delete;

        Application& operator=(Application const& rhs) noexcept = delete;
        Application& operator=(Application&& rhs) noexcept = delete;

        ~Application() noexcept;

        static const Derived& getInstance()
        {
            static Derived instance;
            return instance;
        }

        void run() const noexcept;

    protected:
        explicit Application() noexcept;

        bool m_is_running{true};

        std::unique_ptr<platform::Window> m_window;
        std::unique_ptr<graphics::renderer::Renderer> m_graphics_renderer;

        platform::Platform& m_platform = platform::Platform::getInstance();

    private:
        void onWindowClosed(const event::Event<event::window::WindowEventType>&) { m_is_running = false; }
    };
}

#endif /* NOVUM_ENGINE_APPLICATION_H */

#include "Application.inl"
