/**
 *  @file    GlfwPlatform.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#include <GLFW/glfw3.h>

#include "graphics/backend/opengl/OpenGLContext.h"
#include "platform/Platform.h"
#include "utility/Assertion.hpp"

novum_engine::platform::Platform::Platform(event::EventBus& eventBus) noexcept : m_eventBus(eventBus)
{
    const auto glfw_ret = glfwInit();
    NOVUM_ENGINE_ASSERT(glfw_ret, "GLFW initialization failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_graphics_context = graphics::backend::OpenGLContext
    {
        .glLoadFunc = glfwGetProcAddress
    };
}

std::unique_ptr<novum_engine::platform::Window> novum_engine::platform::Platform::createWindow(const std::string& title, int width, int height) const noexcept
{
    return std::make_unique<Window>(title, width, height, m_eventBus);
}

novum_engine::graphics::backend::OpenGLContext novum_engine::platform::Platform::getGraphicsContext() const noexcept
{
    return m_graphics_context;
}

novum_engine::input::InputContext novum_engine::platform::Platform::getInputContext(const Window& window) const noexcept
{
    return input::InputContext
    {
        .keyboardContext = m_keyboard_device.getKeyboardContext(window),
        .mouseContext = m_mouse_device.getMouseContext(window)
    };
}

void novum_engine::platform::Platform::pollEvents() const noexcept
{
    glfwPollEvents();
}

novum_engine::platform::Platform::~Platform() noexcept
{
    glfwTerminate();
}
