/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_H
#define NOVUM_ENGINE_WINDOW_H

#include <memory>
#include <string>

#include "event/EventBus.hpp"

namespace novum_engine::platform
{
    class Window
    {
    public:
        explicit Window(int width, int height, const std::string& title,
                        event::EventBus& eventDispatcher) noexcept;

        Window(Window const& rhs) noexcept = delete;
        Window(Window&& rhs) noexcept = delete;

        Window& operator=(Window const& rhs) noexcept = delete;
        Window& operator=(Window&& rhs) noexcept = delete;

        ~Window() noexcept;

        void swapBuffers() const noexcept;
        void* getNativeWindow() const noexcept;

    private:
        void onResize(int width, int height) const noexcept;
        void onClose() const noexcept;

        struct WindowImpl;

        std::unique_ptr<WindowImpl> m_native_window;

        event::EventBus& m_event_dispatcher;
    };
}

#endif /* NOVUM_ENGINE_WINDOW_H */
