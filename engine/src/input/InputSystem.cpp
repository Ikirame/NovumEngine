/**
 *  @file    InputSystem.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/02/2026
 **/

#include "input/InputSystem.h"

novum_engine::input::InputSystem::InputSystem(platform::Window& window) : m_keyboard(
    std::make_unique<KeyboardInput>(window)), m_mouse(std::make_unique<MouseInput>(window)) {}

void novum_engine::input::InputSystem::update() const noexcept
{
    m_keyboard->update();
    m_mouse->update();
}
