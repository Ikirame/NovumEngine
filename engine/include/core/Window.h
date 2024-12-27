/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_H
#define NOVUM_ENGINE_WINDOW_H

#include <memory>
#include <string>

// ReSharper disable once CppUnusedIncludeDirective
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "core/event/window/WindowEventType.h"
#include "utility/event/EventDispatcher.hpp"

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

        void onUpdate() const noexcept;

        [[nodiscard]] GLFWwindow* getNativeWindow() const noexcept { return m_native_window.get(); }

        void subscribe(const event::window::WindowEventType& type,
                       const std::function<void(const utility::event::Event<event::window::WindowEventType>&)>&
                       callback) const noexcept
        {
            m_event_dispatcher->subscribe(type, callback);
        }

    private:
        struct GlfwWindowDeleter
        {
            void operator()(GLFWwindow* window) const noexcept
            {
                glfwDestroyWindow(window);
            }
        };

        std::unique_ptr<GLFWwindow, GlfwWindowDeleter> m_native_window;
        std::unique_ptr<utility::event::EventDispatcher<event::window::WindowEventType>> m_event_dispatcher
        {
            std::make_unique<utility::event::EventDispatcher<event::window::WindowEventType>>()
        };

        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        static void windowCloseCallback(GLFWwindow* window);
    };
}

#endif /* NOVUM_ENGINE_WINDOW_H */
