/**
 *  @file    KeyboardDevice.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/26/2026
 **/

#include "platform/devices/KeyboardDevice.h"

#include <unordered_map>

#include "GLFW/glfw3.h"
#include "input/InputSystem.h"

static const std::unordered_map<int, novum_engine::input::KeyboardKey> gflwKeyboardKeysMapping =
{
    // Letters
    {GLFW_KEY_A, novum_engine::input::KeyboardKey::A},
    {GLFW_KEY_B, novum_engine::input::KeyboardKey::B},
    {GLFW_KEY_C, novum_engine::input::KeyboardKey::C},
    {GLFW_KEY_D, novum_engine::input::KeyboardKey::D},
    {GLFW_KEY_E, novum_engine::input::KeyboardKey::E},
    {GLFW_KEY_F, novum_engine::input::KeyboardKey::F},
    {GLFW_KEY_G, novum_engine::input::KeyboardKey::G},
    {GLFW_KEY_H, novum_engine::input::KeyboardKey::H},
    {GLFW_KEY_I, novum_engine::input::KeyboardKey::I},
    {GLFW_KEY_J, novum_engine::input::KeyboardKey::J},
    {GLFW_KEY_K, novum_engine::input::KeyboardKey::K},
    {GLFW_KEY_L, novum_engine::input::KeyboardKey::L},
    {GLFW_KEY_M, novum_engine::input::KeyboardKey::M},
    {GLFW_KEY_N, novum_engine::input::KeyboardKey::N},
    {GLFW_KEY_O, novum_engine::input::KeyboardKey::O},
    {GLFW_KEY_P, novum_engine::input::KeyboardKey::P},
    {GLFW_KEY_Q, novum_engine::input::KeyboardKey::Q},
    {GLFW_KEY_R, novum_engine::input::KeyboardKey::R},
    {GLFW_KEY_S, novum_engine::input::KeyboardKey::S},
    {GLFW_KEY_T, novum_engine::input::KeyboardKey::T},
    {GLFW_KEY_U, novum_engine::input::KeyboardKey::U},
    {GLFW_KEY_V, novum_engine::input::KeyboardKey::V},
    {GLFW_KEY_W, novum_engine::input::KeyboardKey::W},
    {GLFW_KEY_X, novum_engine::input::KeyboardKey::X},
    {GLFW_KEY_Y, novum_engine::input::KeyboardKey::Y},
    {GLFW_KEY_Z, novum_engine::input::KeyboardKey::Z},

    // Numbers
    {GLFW_KEY_0, novum_engine::input::KeyboardKey::Num0},
    {GLFW_KEY_1, novum_engine::input::KeyboardKey::Num1},
    {GLFW_KEY_2, novum_engine::input::KeyboardKey::Num2},
    {GLFW_KEY_3, novum_engine::input::KeyboardKey::Num3},
    {GLFW_KEY_4, novum_engine::input::KeyboardKey::Num4},
    {GLFW_KEY_5, novum_engine::input::KeyboardKey::Num5},
    {GLFW_KEY_6, novum_engine::input::KeyboardKey::Num6},
    {GLFW_KEY_7, novum_engine::input::KeyboardKey::Num7},
    {GLFW_KEY_8, novum_engine::input::KeyboardKey::Num8},
    {GLFW_KEY_9, novum_engine::input::KeyboardKey::Num9},

    // Controls
    {GLFW_KEY_SPACE, novum_engine::input::KeyboardKey::Space},
    {GLFW_KEY_ENTER, novum_engine::input::KeyboardKey::Enter},
    {GLFW_KEY_TAB, novum_engine::input::KeyboardKey::Tab},
    {GLFW_KEY_ESCAPE, novum_engine::input::KeyboardKey::Escape},
    {GLFW_KEY_BACKSPACE, novum_engine::input::KeyboardKey::Backspace},

    // Modifiers
    {GLFW_KEY_LEFT_SHIFT, novum_engine::input::KeyboardKey::LeftShift},
    {GLFW_KEY_RIGHT_SHIFT, novum_engine::input::KeyboardKey::RightShift},
    {GLFW_KEY_LEFT_CONTROL, novum_engine::input::KeyboardKey::LeftCtrl},
    {GLFW_KEY_RIGHT_CONTROL, novum_engine::input::KeyboardKey::RightCtrl},
    {GLFW_KEY_LEFT_ALT, novum_engine::input::KeyboardKey::LeftAlt},
    {GLFW_KEY_RIGHT_ALT, novum_engine::input::KeyboardKey::RightAlt},

    // Arrows
    {GLFW_KEY_UP, novum_engine::input::KeyboardKey::Up},
    {GLFW_KEY_DOWN, novum_engine::input::KeyboardKey::Down},
    {GLFW_KEY_LEFT, novum_engine::input::KeyboardKey::Left},
    {GLFW_KEY_RIGHT, novum_engine::input::KeyboardKey::Right},

    // Function keys
    {GLFW_KEY_F1, novum_engine::input::KeyboardKey::F1},
    {GLFW_KEY_F2, novum_engine::input::KeyboardKey::F2},
    {GLFW_KEY_F3, novum_engine::input::KeyboardKey::F3},
    {GLFW_KEY_F4, novum_engine::input::KeyboardKey::F4},
    {GLFW_KEY_F5, novum_engine::input::KeyboardKey::F5},
    {GLFW_KEY_F6, novum_engine::input::KeyboardKey::F6},
    {GLFW_KEY_F7, novum_engine::input::KeyboardKey::F7},
    {GLFW_KEY_F8, novum_engine::input::KeyboardKey::F8},
    {GLFW_KEY_F9, novum_engine::input::KeyboardKey::F9},
    {GLFW_KEY_F10, novum_engine::input::KeyboardKey::F10},
    {GLFW_KEY_F11, novum_engine::input::KeyboardKey::F11},
    {GLFW_KEY_F12, novum_engine::input::KeyboardKey::F12},
};

novum_engine::input::KeyboardContext novum_engine::platform::devices::KeyboardDevice::getKeyboardContext(
    const Window& window) const noexcept
{
    input::KeyboardContext context;

    const auto glfwWindow = static_cast<GLFWwindow*>(window.getNativeWindow());
    for (auto [key, value] : gflwKeyboardKeysMapping)
    {
        const auto state = glfwGetKey(glfwWindow, key);

        context.keys[value] = (context.keys[value] & 1 << 0 ? 1 << 1 : 0) |
                              (state ? 1 << 0 : 0);
    }

    return context;
}
