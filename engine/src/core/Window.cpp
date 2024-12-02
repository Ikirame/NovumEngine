/**
 *  @file    Window.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include "platform/opengl/Context.h"

#include "utility/Assertion.hpp"
#include "utility/event/Event.hpp"

#include "event/window/WindowClosedEvent.h"
#include "event/window/WindowEventDispatcher.h"

#include "Window.h"

novum_engine::core::Window::Window(const int width, const int height, const std::string& title) noexcept
{
    const auto glfw_ret = glfwInit();
    CORE_ASSERT(glfw_ret, "GLFW initialization failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, platform::opengl::opengl_version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, platform::opengl::opengl_version_minor);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif /* __APPLE__ */

    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        CORE_ASSERT(window, "GLFW window creation failed");
    }

    m_native_window.reset(window);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowCloseCallback(window, window_close_callback);

    if (const auto glad_ret = gladLoadGL(glfwGetProcAddress); !glad_ret)
    {
        glfwTerminate();
        CORE_ASSERT(glad_ret, "GLAD initialization failed");
    }

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " <<
        glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n' << std::endl;
#endif /* NDEBUG */
}

void novum_engine::core::Window::onUpdate() const noexcept
{
    glfwSwapBuffers(m_native_window.get());
    glfwPollEvents();
}

void novum_engine::core::Window::framebuffer_size_callback(GLFWwindow*, const int width, const int height)
{
    glViewport(0, 0, width, height);
}

void novum_engine::core::Window::window_close_callback(GLFWwindow*)
{
    event::WindowClosedEvent window_event;

    WindowEventDispatcher& dispatcher = WindowEventDispatcher::getInstance();

    dispatcher.post(window_event);
}
