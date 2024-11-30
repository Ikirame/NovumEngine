/**
 *  @file    Window.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include "Window.h"

#include "platform/opengl/Context.h"
#include "utility/Assertion.hpp"

novum_engine::core::Window::Window(int width, int height, const std::string& title) noexcept
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
    //while (!glfwWindowShouldClose(m_glfw_window.get()))
    //{
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glUseProgram(shaderProgram);
    //vao.bind();
    //glDrawArrays(GL_TRIANGLES, 0, 3);

    //glfwSwapBuffers(m_glfw_window.get());
    //glfwPollEvents();
    //}
}

void novum_engine::core::Window::framebuffer_size_callback(GLFWwindow*, const int width, const int height)
{
    glViewport(0, 0, width, height);
}

