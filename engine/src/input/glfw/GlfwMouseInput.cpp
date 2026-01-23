/**
 *  @file    GlfwMouseInput.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/07/2026
 **/

#include <GLFW/glfw3.h>

#include "input/InputSystem.h"
#include "input/MouseInput.h"

struct novum_engine::input::MouseInput::MouseInputImpl
{
    explicit MouseInputImpl(const platform::Window& window) noexcept
    {
        m_window = static_cast<GLFWwindow*>(window.getNativeWindow());

        m_buttons_mapping =
        {
            {LEFT_BUTTON, GLFW_MOUSE_BUTTON_LEFT},
            {RIGHT_BUTTON, GLFW_MOUSE_BUTTON_RIGHT},
            {MIDDLE_BUTTON, GLFW_MOUSE_BUTTON_MIDDLE}
        };

        m_state_mapping =
        {
            {GLFW_PRESS, Press},
            {GLFW_RELEASE, Release}
        };
    }

    InputState getButtonState(const MouseInputButton button) const
    {
        const auto glfwKey = m_buttons_mapping.at(button);
        const auto state = glfwGetMouseButton(m_window, glfwKey);

        return m_state_mapping.at(state);
    }

private:
    std::unordered_map<MouseInputButton, uint8_t> m_buttons_mapping;
    std::unordered_map<uint8_t, InputState> m_state_mapping;

    GLFWwindow *m_window;
};

novum_engine::input::MouseInput::MouseInput(platform::Window& window) : m_native_input(
    std::make_unique<MouseInputImpl>(window)) {}

void novum_engine::input::MouseInput::update() noexcept
{
    for (auto& button : m_buttons)
    {
        const auto mouseInputButton = static_cast<MouseInputButton>(button);
        const auto state = m_native_input->getButtonState(mouseInputButton);

        button = (button & Current ? Previous : 0) |
                 (state == Press ? Current : 0);
    }
}

bool novum_engine::input::MouseInput::isButtonPressed(const MouseInputButton button) const noexcept
{
    return m_buttons[button] & Current;
}

novum_engine::input::MouseInput::~MouseInput() {}
