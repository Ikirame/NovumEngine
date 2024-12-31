/**
 *  @file    RenderApi.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "render/api/opengl/RenderApi.h"

#include "utility/Assertion.hpp"

novum_engine::render::api::opengl::RenderApi::RenderApi() noexcept
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif /* __APPLE__ */

    const auto glad_ret = gladLoadGL(glfwGetProcAddress);
    CORE_ASSERT(!glad_ret, "GLAD initialization failed");

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " <<
        glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n' << std::endl;
#endif /* NDEBUG */
}

void novum_engine::render::api::opengl::RenderApi::resizeViewport(const int x, const int y, const int width,
                                                                  const int height) noexcept
{
    glViewport(x, y, width, height);
}
