/**
 *  @file    KeyboardDevice.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/26/2026
 **/

#ifndef NOVUM_ENGINE_KEYBOARD_DEVICE_H
#define NOVUM_ENGINE_KEYBOARD_DEVICE_H

#include "input/KeyboardContext.h"
#include "platform/Window.h"

namespace novum_engine::platform::devices
{
    class KeyboardDevice
    {
    public:
        explicit KeyboardDevice() = default;

        KeyboardDevice(KeyboardDevice const& rhs) noexcept = delete;
        KeyboardDevice(KeyboardDevice&& rhs) noexcept = delete;

        KeyboardDevice& operator=(KeyboardDevice const& rhs) noexcept = delete;
        KeyboardDevice& operator=(KeyboardDevice&& rhs) noexcept = delete;

        [[nodiscard]] input::KeyboardContext getKeyboardContext(const Window& window) const noexcept;
    };
}

#endif /* NOVUM_ENGINE_KEYBOARD_DEVICE_H */
