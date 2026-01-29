/**
 *  @file    MouseContext.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/07/2026
 **/

#ifndef NOVUM_ENGINE_MOUSE_CONTEXT_H
#define NOVUM_ENGINE_MOUSE_CONTEXT_H

#include <array>
#include <cstdint>

namespace novum_engine::input
{
    enum MouseButton : uint8_t
    {
        LEFT_BUTTON,
        RIGHT_BUTTON,
        MIDDLE_BUTTON,
    };

    struct MousePosition
    {
        double x;
        double y;
    };

    struct MouseContext
    {
        std::array<uint8_t, 3> buttons;
        MousePosition position;
    };
}

#endif /* NOVUM_ENGINE_MOUSE_CONTEXT_H */