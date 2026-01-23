/**
 *  @file    GlfwPlatform.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#include <GLFW/glfw3.h>

#include "graphics/backend/opengl/OpenGLContext.h"
#include "platform/Platform.h"
#include "utility/Assertion.hpp"

novum_engine::platform::Platform::Platform(const graphics::GraphicsBackend graphicsBackend,
                                           event::EventBus& eventBus) noexcept : m_eventBus(eventBus)
{
    const auto glfw_ret = glfwInit();
    NOVUM_ENGINE_ASSERT(glfw_ret, "GLFW initialization failed");

    // Todo: Create Factory to setup graphics context
    if (graphicsBackend == graphics::GraphicsBackend::OpenGL)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        auto openGlContext = graphics::backend::OpenGLContext{};
        openGlContext.glLoadFunc = glfwGetProcAddress;
        m_graphics_context.emplace(openGlContext);
    }
}

std::unique_ptr<novum_engine::platform::Window> novum_engine::platform::Platform::createWindow(const std::string& title, int width, int height) const noexcept
{
    return std::make_unique<Window>(title, width, height, m_eventBus);
}

void novum_engine::platform::Platform::pollEvents() const noexcept
{
    glfwPollEvents();
}

novum_engine::platform::Platform::~Platform() noexcept
{
    glfwTerminate();
}
