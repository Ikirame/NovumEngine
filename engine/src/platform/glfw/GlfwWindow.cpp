/**
 *  @file    GlfwWindow.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include <GLFW/glfw3.h>

#include "utility/Assertion.hpp"

#include "event/window/WindowEvent.h"

#include "platform/Window.h"

struct novum_engine::platform::Window::WindowImpl
{
    explicit WindowImpl(const int width, const int height, const std::string& title)
    {
        GLFWwindow *window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        NOVUM_ENGINE_ASSERT(window != nullptr, "GLFW window creation failed");

        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, this);

        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
        glfwSetWindowCloseCallback(window, windowCloseCallback);

        m_handle.reset(window);
    }

    void swapBuffers() const
    {
        glfwSwapBuffers(m_handle.get());
    }

    GLFWwindow* getNativeWindow() const noexcept
    {
        return m_handle.get();
    }

    std::function<void()> onClose = [] {};
    std::function<void(int, int)> onResize = [](int, int) {};

    static void windowCloseCallback(GLFWwindow *window)
    {
        const auto self = static_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
        self->onClose();
    }

    static void framebufferSizeCallback(GLFWwindow *window, const int width, const int height)
    {
        const auto self = static_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
        self->onResize(width, height);
    }

private:
    struct GlfwWindowDeleter
    {
        void operator()(GLFWwindow *window) const noexcept
        {
            glfwDestroyWindow(window);
        }
    };

    std::unique_ptr<GLFWwindow, GlfwWindowDeleter> m_handle;
};

novum_engine::platform::Window::Window(const int width, const int height,
                                       const std::string& title,
                                       event::EventBus& eventDispatcher) noexcept : m_native_window(
        std::make_unique<WindowImpl>(width, height, title)), m_event_dispatcher(eventDispatcher)
{
    m_native_window->onClose = [this] { this->onClose(); };
    m_native_window->onResize = [this](const int w, const int h) { this->onResize(w, h); };
}

novum_engine::platform::Window::~Window() noexcept = default;

void novum_engine::platform::Window::swapBuffers() const noexcept
{
    m_native_window->swapBuffers();
}

void* novum_engine::platform::Window::getNativeWindow() const noexcept
{
    return m_native_window->getNativeWindow();
}

void novum_engine::platform::Window::onResize(const int width, const int height) const noexcept
{
    const event::window::WindowResizedEvent resizedEvent(width, height);
    m_event_dispatcher.publish(resizedEvent);
}

void novum_engine::platform::Window::onClose() const noexcept
{
    const event::window::WindowClosedEvent closedEvent;
    m_event_dispatcher.publish(closedEvent);
}
