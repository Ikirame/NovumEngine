/**
 *  @file    InputSystem.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/02/2026
 **/

#ifndef NOVUM_ENGINE_INPUT_SYSTEM_H
#define NOVUM_ENGINE_INPUT_SYSTEM_H

#include "InputContext.h"
#include "platform/Window.h"

namespace novum_engine::input
{
    enum InputState : uint8_t
    {
        Press,
        Release,
        Hold
    };

    class InputSystem
    {
    public:
        explicit InputSystem() = default;

        InputSystem(InputSystem const& rhs) noexcept = delete;
        InputSystem(InputSystem&& rhs) noexcept = delete;

        InputSystem& operator=(InputSystem const& rhs) noexcept = delete;
        InputSystem& operator=(InputSystem&& rhs) noexcept = delete;

        void update(const InputContext& inputContext) noexcept;

        [[nodiscard]] bool isKeyPressed(KeyboardKey key) const noexcept;

        [[nodiscard]] bool isButtonPressed(MouseButton key) const noexcept;
        [[nodiscard]] MousePosition getMousePosition() const noexcept;

    private:
        KeyboardContext m_keyboard_context;
        MouseContext m_mouse_context;
    };
}

#endif /* NOVUM_ENGINE_INPUT_SYSTEM_H */
