/**
 *  @file    OpenglGraphicsApi.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "graphics/api/opengl/OpenglGraphicsApi.h"

#include "utility/Assertion.hpp"

novum_engine::graphics::api::opengl::OpenglGraphicsApi::OpenglGraphicsApi() noexcept
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const auto glad_ret = gladLoadGL(glfwGetProcAddress);
    CORE_ASSERT(!glad_ret, "GLAD initialization failed");

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " <<
        glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n' << std::endl;
#endif /* NDEBUG */
}

void novum_engine::graphics::api::opengl::OpenglGraphicsApi::resizeViewport(const int x, const int y, const int width,
                                                                            const int height) noexcept
{
    glViewport(x, y, width, height);
}

void novum_engine::graphics::api::opengl::OpenglGraphicsApi::render() noexcept
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
