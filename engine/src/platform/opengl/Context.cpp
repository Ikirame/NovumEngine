/**
 *  @file    Context.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    10/10/2022
 */

#include <iostream>
#include <memory>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include "platform/opengl/Context.h"
#include "core/Window.h"
#include "utility/Assertion.hpp"

novum_engine::platform::opengl::Context::Context() noexcept
{
    const auto glfw_ret = glfwInit();
    CORE_ASSERT(glfw_ret && "GLFW initialization failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_version_minor);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif /* __APPLE__ */

    m_window = std::make_unique<core::Window>();

    if (const auto glad_ret = gladLoadGL(glfwGetProcAddress); !glad_ret)
    {
        glfwTerminate();
        CORE_ASSERT(glad_ret && "GLAD initialization failed");
    }

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " <<
        glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n' << std::endl;
#endif /* NDEBUG */
}

novum_engine::platform::opengl::Context::~Context() noexcept
{
    glfwTerminate();
}
