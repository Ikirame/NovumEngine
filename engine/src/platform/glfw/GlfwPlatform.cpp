/**
 *  @file    GlfwPlatform.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#include <GLFW/glfw3.h>

#include "platform/Platform.h"
#include "utility/Assertion.hpp"

std::unique_ptr<novum_engine::core::Window> novum_engine::platform::Platform::createWindow() const noexcept
{
    return std::make_unique<core::Window>(800, 600, "novumEngine");
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
