/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/10/2024
 **/

#include "glad/gl.h"

#include "core/Window.h"
#include "utility/Assertion.hpp"

novum_engine::core::Window::Window(const int width, const int height, std::string const& title) noexcept
{
    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        CORE_ASSERT(window && "GLFW window creation failed");
    }

    m_glfw_window.reset(window);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void novum_engine::core::Window::render() const
{
    while (!glfwWindowShouldClose(m_glfw_window.get()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(m_glfw_window.get());
        glfwPollEvents();
    }
}

void novum_engine::core::Window::framebuffer_size_callback(GLFWwindow*, const int width, const int height)
{
    glViewport(0, 0, width, height);
}
