/**
 *  @file    MouseDevice.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/28/2026
 **/

#ifndef NOVUM_ENGINE_MOUSE_DEVICE_H
#define NOVUM_ENGINE_MOUSE_DEVICE_H

#include "input/MouseContext.h"
#include "platform/Window.h"

namespace novum_engine::platform::devices
{
    class MouseDevice
    {
    public:
        explicit MouseDevice() = default;

        MouseDevice(MouseDevice const& rhs) noexcept = delete;
        MouseDevice(MouseDevice&& rhs) noexcept = delete;

        MouseDevice& operator=(MouseDevice const& rhs) noexcept = delete;
        MouseDevice& operator=(MouseDevice&& rhs) noexcept = delete;

        [[nodiscard]] input::MouseContext getMouseContext(const Window& window) const noexcept;
    };
}

#endif /* NOVUM_ENGINE_MOUSE_DEVICE_H */
