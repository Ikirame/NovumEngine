/**
 *  @file    MouseDevice.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/28/2026
 **/

#include "platform/devices/MouseDevice.h"

#include "GLFW/glfw3.h"

static const std::unordered_map<int, novum_engine::input::MouseButton> gflwMouseButtonsMapping =
{
    {GLFW_MOUSE_BUTTON_LEFT, novum_engine::input::MouseButton::LEFT_BUTTON},
    {GLFW_MOUSE_BUTTON_RIGHT, novum_engine::input::MouseButton::RIGHT_BUTTON},
    {GLFW_MOUSE_BUTTON_MIDDLE, novum_engine::input::MouseButton::MIDDLE_BUTTON},
};

novum_engine::input::MouseContext novum_engine::platform::devices::MouseDevice::getMouseContext(
    const Window& window) const noexcept
{
    input::MouseContext context;

    const auto glfwWindow = static_cast<GLFWwindow*>(window.getNativeWindow());
    for (auto [key, value] : gflwMouseButtonsMapping)
    {
        const auto state = glfwGetMouseButton(glfwWindow, key);

        context.buttons[value] = (context.buttons[value] & 1 << 0 ? 1 << 1 : 0) |
                                 (state ? 1 << 0 : 0);
    }

    auto mousePosition = input::MousePosition{};
    glfwGetCursorPos(glfwWindow, &mousePosition.x, &mousePosition.y);

    context.position = mousePosition;

    return context;
}
