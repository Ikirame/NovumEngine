/**
 *  @file    Window.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include "utility/Assertion.hpp"

#include "event/window/WindowClosedEvent.h"
#include "event/window/WindowResizedEvent.h"

#include "Window.h"

#include "render/api/opengl/RenderApi.h"

novum_engine::core::Window::Window(const int width, const int height, const std::string& title) noexcept
{
    const auto glfw_ret = glfwInit();
    CORE_ASSERT(glfw_ret, "GLFW initialization failed");

    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        CORE_ASSERT(window, "GLFW window creation failed");
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetWindowUserPointer(window, this);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetWindowCloseCallback(window, windowCloseCallback);

    m_native_window.reset(window);
    m_render_api = std::make_unique<render::api::opengl::RenderApi>();
}

void novum_engine::core::Window::onUpdate() const noexcept
{
    glfwSwapBuffers(m_native_window.get());
    glfwPollEvents();
}

void novum_engine::core::Window::framebufferSizeCallback(GLFWwindow* window, const int width, const int height)
{
    const Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
    render::api::opengl::RenderApi::resizeViewport(0, 0, width, height);

    event::window::WindowResizedEvent window_event{width, height};
    self->m_event_dispatcher->post(window_event);
}

void novum_engine::core::Window::windowCloseCallback(GLFWwindow* window)
{
    const Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

    event::window::WindowClosedEvent window_event;
    self->m_event_dispatcher->post(window_event);
}
