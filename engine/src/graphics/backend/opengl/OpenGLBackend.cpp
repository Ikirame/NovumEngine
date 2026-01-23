/**
 *  @file    OpenGLBackend.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#include <format>

#include <glad/gl.h>

#include "graphics/backend/opengl/OpenGLBackend.h"

#include "utility/Assertion.hpp"
#include "utility/Logger.h"

novum_engine::graphics::backend::opengl::OpenGLBackend::OpenGLBackend(platform::Platform& platform) noexcept
{
    // Todo: Check if the backend should get the graphics context or if it should be provided by the renderer
    auto [glLoadFunc] = platform.getGraphicsContext<OpenGLContext>();
    const auto glad_ret = gladLoadGL(glLoadFunc);

    NOVUM_ENGINE_ASSERT(glad_ret, "GLAD initialization failed");

#ifdef NOVUM_ENGINE_DEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
    glDebugMessageCallback([](const GLenum, const GLenum, GLuint, const GLenum, const GLsizei, const GLchar *msg,
                              const void *)
    {
        NOVUM_ENGINE_LOG_ERROR(std::format("[GL DEBUG] {}", msg));
    }, nullptr);

    NOVUM_ENGINE_LOG_DEBUG(std::format("OpenGL {}, GLSL {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)),
        reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION))));
#endif
}

void novum_engine::graphics::backend::opengl::OpenGLBackend::beginFrame() const noexcept
{
    glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void novum_engine::graphics::backend::opengl::OpenGLBackend::draw() const noexcept {}
void novum_engine::graphics::backend::opengl::OpenGLBackend::endFrame() const noexcept {}

void novum_engine::graphics::backend::opengl::OpenGLBackend::resizeViewport(const int x, const int y, const int width,
                                                                            const int height) const noexcept
{
    glViewport(x, y, width, height);
}
