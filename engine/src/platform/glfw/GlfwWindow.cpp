/**
 *  @file    GlfwWindow.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include <GLFW/glfw3.h>

#include "utility/Assertion.hpp"

#include "event/window/WindowEvent.h"
#include "graphics/api/opengl/OpenglGraphicsApi.h"

#include "platform/Window.h"

struct novum_engine::core::Window::WindowImpl
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

novum_engine::core::Window::Window(const int width, const int height,
                                   const std::string& title) noexcept : m_native_window(
    std::make_unique<WindowImpl>(width, height, title))
{
    m_native_window->onClose = [this] { this->onClose(); };
    m_native_window->onResize = [this](const int w, const int h) { this->onResize(w, h); };

    m_graphics_api = std::make_unique<graphics::api::opengl::OpenglGraphicsApi>();
}

novum_engine::core::Window::~Window() noexcept = default;

void novum_engine::core::Window::update() const noexcept
{
    m_native_window->swapBuffers();
}

void novum_engine::core::Window::onResize(const int width, const int height) noexcept
{
    event::window::WindowResizedEvent resized_event(width, height);
    m_event_dispatcher.post(resized_event);
}

void novum_engine::core::Window::onClose() noexcept
{
    event::window::WindowEvent window_event;
    m_event_dispatcher.post(window_event);
}
