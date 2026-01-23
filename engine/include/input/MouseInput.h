/**
 *  @file    MouseInput.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/07/2026
 **/

#ifndef NOVUM_ENGINE_MOUSE_INPUT_H
#define NOVUM_ENGINE_MOUSE_INPUT_H

#include <memory>

#include "platform/Window.h"

namespace novum_engine::input
{
    enum MouseInputButton : uint8_t
    {
        LEFT_BUTTON,
        RIGHT_BUTTON,
        MIDDLE_BUTTON,
    };

    class MouseInput
    {
    public:
        explicit MouseInput(platform::Window& window);

        MouseInput(MouseInput const& rhs) noexcept = delete;
        MouseInput(MouseInput&& rhs) noexcept = delete;

        MouseInput& operator=(MouseInput const& rhs) noexcept = delete;
        MouseInput& operator=(MouseInput&& rhs) noexcept = delete;

        void update() noexcept;

        [[nodiscard]] bool isButtonPressed(MouseInputButton button) const noexcept;

        ~MouseInput();

    private:
        struct MouseInputImpl;

        static constexpr size_t MaxButtons = 3;

        static constexpr uint8_t Current = 1 << 0;
        static constexpr uint8_t Previous = 1 << 1;

        std::unique_ptr<MouseInputImpl> m_native_input;

        std::array<uint8_t, MaxButtons> m_buttons{};
    };
}

#endif /* NOVUM_ENGINE_MOUSE_INPUT_H */
