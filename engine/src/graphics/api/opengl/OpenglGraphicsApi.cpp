/**
 *  @file    OpenglGraphicsApi.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "graphics/api/opengl/OpenglGraphicsApi.h"

#include "utility/Assertion.hpp"
#include "utility/Logging.hpp"

novum_engine::graphics::api::opengl::OpenglGraphicsApi::OpenglGraphicsApi() noexcept
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const auto glad_ret = gladLoadGL(glfwGetProcAddress);
    NOVUM_ENGINE_ASSERT(glad_ret, "GLAD initialization failed");

#ifdef NOVUM_ENGINE_DEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
    glDebugMessageCallback([](const GLenum, const GLenum, GLuint, const GLenum, const GLsizei, const GLchar *msg,
                              const void *)
    {
        spdlog::error("[GL DEBUG] {}", msg);
    }, nullptr);

    NOVUM_ENGINE_LOG_DEBUG("OpenGL {}, GLSL {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)),
                           reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
#endif
}

void novum_engine::graphics::api::opengl::OpenglGraphicsApi::resizeViewport(const int x, const int y, const int width,
                                                                            const int height) noexcept
{
    glViewport(x, y, width, height);
}

void novum_engine::graphics::api::opengl::OpenglGraphicsApi::render() noexcept
{
    glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
