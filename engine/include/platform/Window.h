/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_H
#define NOVUM_ENGINE_WINDOW_H

#include <memory>
#include <string>

#include "graphics/api/opengl/OpenglGraphicsApi.h"

#include "event/EventDispatcher.hpp"
#include "event/window/WindowEvent.h"

namespace novum_engine::core
{
    class Window
    {
    public:
        explicit Window(int width, int height, const std::string& title) noexcept;

        Window(Window const& rhs) noexcept = delete;
        Window(Window&& rhs) noexcept = delete;

        Window& operator=(Window const& rhs) noexcept = delete;
        Window& operator=(Window&& rhs) noexcept = delete;

        ~Window() noexcept;

        void update() const noexcept;

        void subscribe(const event::window::WindowEventType& type,
                       const std::function<void(const event::Event<event::window::WindowEventType>&)>&
                       callback) noexcept
        {
            m_event_dispatcher.subscribe(type, callback);
        }

    private:
        void onResize(int width, int height) noexcept;
        void onClose() noexcept;

        struct WindowImpl;

        std::unique_ptr<WindowImpl> m_native_window;
        std::unique_ptr<graphics::api::opengl::OpenglGraphicsApi> m_graphics_api;

        event::EventDispatcher<event::window::WindowEventType> m_event_dispatcher;
    };
}

#endif /* NOVUM_ENGINE_WINDOW_H */
