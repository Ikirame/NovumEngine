/**
 *  @file    InputSystem.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/02/2026
 **/

#ifndef NOVUM_ENGINE_INPUT_SYSTEM_H
#define NOVUM_ENGINE_INPUT_SYSTEM_H

#include "platform/Window.h"

#include "KeyboardInput.h"
#include "MouseInput.h"

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
        explicit InputSystem(std::unique_ptr<platform::Window>& window);

        InputSystem(InputSystem const& rhs) noexcept = delete;
        InputSystem(InputSystem&& rhs) noexcept = delete;

        InputSystem& operator=(InputSystem const& rhs) noexcept = delete;
        InputSystem& operator=(InputSystem&& rhs) noexcept = delete;

        void update() const noexcept;

        KeyboardInput& getKeyboardInput() const noexcept { return *m_keyboard; }
        MouseInput& getMouseInput() const noexcept { return *m_mouse; }

    private:
        std::unique_ptr<KeyboardInput> m_keyboard;
        std::unique_ptr<MouseInput> m_mouse;
    };
}

#endif /* NOVUM_ENGINE_INPUT_SYSTEM_H */
