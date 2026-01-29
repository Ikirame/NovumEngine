/**
 *  @file    InputSystem.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/02/2026
 **/

#include "input/InputSystem.h"

void novum_engine::input::InputSystem::update(const InputContext& inputContext) noexcept
{
    m_keyboard_context = inputContext.keyboardContext;
    m_mouse_context = inputContext.mouseContext;
}

bool novum_engine::input::InputSystem::isKeyPressed(const KeyboardKey key) const noexcept
{
    return m_keyboard_context.keys[key] & 1 << 0;
}

bool novum_engine::input::InputSystem::isButtonPressed(const MouseButton key) const noexcept
{
    return m_mouse_context.buttons[key] & 1 << 0;
}

novum_engine::input::MousePosition novum_engine::input::InputSystem::getMousePosition() const noexcept
{
    return m_mouse_context.position;
}
