/**
 *  @file    KeyboardInput.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/07/2026
 **/

#ifndef NOVUM_ENGINE_KEYBOARD_INPUT_H
#define NOVUM_ENGINE_KEYBOARD_INPUT_H

#include <memory>

#include "platform/Window.h"

namespace novum_engine::input
{
    enum KeyboardInputKey : uint8_t
    {
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
    };

    class KeyboardInput
    {
    public:
        explicit KeyboardInput(std::unique_ptr<platform::Window>& window);

        KeyboardInput(KeyboardInput const& rhs) noexcept = delete;
        KeyboardInput(KeyboardInput&& rhs) noexcept = delete;

        KeyboardInput& operator=(KeyboardInput const& rhs) noexcept = delete;
        KeyboardInput& operator=(KeyboardInput&& rhs) noexcept = delete;

        void update() noexcept;

        [[nodiscard]] bool isKeyPressed(KeyboardInputKey key) const noexcept;

        ~KeyboardInput();

    private:
        struct KeyboardInputImpl;

        static constexpr size_t MaxKeys = 5;

        static constexpr uint8_t Current = 1 << 0;
        static constexpr uint8_t Previous = 1 << 1;

        std::unique_ptr<KeyboardInputImpl> m_native_input;

        std::array<uint8_t, MaxKeys> m_keys{};
    };
}

#endif /* NOVUM_ENGINE_KEYBOARD_INPUT_H */
