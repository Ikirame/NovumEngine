/**
 *  @file    GlfwPlatform.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#include <GLFW/glfw3.h>

#include "platform/Platform.h"
#include "utility/Assertion.hpp"

std::unique_ptr<novum_engine::platform::Window> novum_engine::platform::Platform::createWindow() const noexcept
{
    return std::make_unique<Window>(800, 600, "NovumEngine");
}

std::unique_ptr<novum_engine::graphics::backend::opengl::OpenGLBackend>
novum_engine::platform::Platform::createGraphicsBackend() const noexcept
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return std::make_unique<graphics::backend::opengl::OpenGLBackend>(glfwGetProcAddress);
}

novum_engine::platform::Platform::Platform() noexcept
{
    const auto glfw_ret = glfwInit();
    NOVUM_ENGINE_ASSERT(glfw_ret, "GLFW initialization failed");
}

novum_engine::platform::Platform::~Platform() noexcept
{
    glfwTerminate();
}

void novum_engine::platform::Platform::pollEvents() const noexcept
{
    glfwPollEvents();
}
