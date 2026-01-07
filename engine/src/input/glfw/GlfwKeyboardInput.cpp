/**
 *  @file    GlfwKeyboardInput.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/07/2026
 **/

#include <memory>
#include <GLFW/glfw3.h>

#include "input/InputSystem.h"
#include "input/KeyboardInput.h"
#include "platform/Window.h"

struct novum_engine::input::KeyboardInput::KeyboardInputImpl
{
    explicit KeyboardInputImpl(const std::unique_ptr<platform::Window>& window) noexcept
    {
        m_window = static_cast<GLFWwindow*>(window->getNativeWindow());

        m_keys_mapping =
        {
            {KEY_A, GLFW_KEY_A},
            {KEY_B, GLFW_KEY_B},
            {KEY_C, GLFW_KEY_C},
            {KEY_D, GLFW_KEY_D},
            {KEY_E, GLFW_KEY_E}
        };

        m_state_mapping =
        {
            {GLFW_PRESS, Press},
            {GLFW_RELEASE, Release}
        };
    }

    InputState getKeyState(const KeyboardInputKey key) const
    {
        const auto glfwKey = m_keys_mapping.at(key);
        const auto state = glfwGetKey(m_window, glfwKey);

        return m_state_mapping.at(state);
    }

private:
    std::unordered_map<KeyboardInputKey, uint8_t> m_keys_mapping;
    std::unordered_map<uint8_t, InputState> m_state_mapping;

    GLFWwindow *m_window;
};

novum_engine::input::KeyboardInput::KeyboardInput(std::unique_ptr<platform::Window>& window) : m_native_input(
    std::make_unique<KeyboardInputImpl>(window)) {}

void novum_engine::input::KeyboardInput::update() noexcept
{
    for (auto& key : m_keys)
    {
        const auto keyboardInputKey = static_cast<KeyboardInputKey>(key);
        const auto state = m_native_input->getKeyState(keyboardInputKey);

        key = (key & Current ? Previous : 0) |
              (state == Press ? Current : 0);
    }
}

bool novum_engine::input::KeyboardInput::isKeyPressed(const KeyboardInputKey key) const noexcept
{
    return m_keys[key] & Current;
}

novum_engine::input::KeyboardInput::~KeyboardInput() {}
