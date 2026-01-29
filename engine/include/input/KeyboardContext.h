/**
 *  @file    KeyboardContext.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/26/2026
 **/

#ifndef NOVUM_ENGINE_KEYBOARD_CONTEXT_H
#define NOVUM_ENGINE_KEYBOARD_CONTEXT_H

#include <array>
#include <cstdint>

namespace novum_engine::input
{
    enum KeyboardKey : uint16_t
    {
        // Letters
        A, B, C, D, E, F, G,
        H, I, J, K, L, M,
        N, O, P, Q, R, S,
        T, U, V, W, X, Y, Z,

        // Numbers
        Num0, Num1, Num2, Num3, Num4,
        Num5, Num6, Num7, Num8, Num9,

        // Controls
        Space,
        Enter,
        Tab,
        Escape,
        Backspace,

        // Modifiers
        LeftShift,
        RightShift,
        LeftCtrl,
        RightCtrl,
        LeftAlt,
        RightAlt,

        // Arrows
        Up,
        Down,
        Left,
        Right,

        // Function keys
        F1, F2, F3, F4, F5, F6,
        F7, F8, F9, F10, F11, F12
    };

    struct KeyboardContext
    {
        std::array<uint16_t, 63> keys;
    };
}

#endif /* NOVUM_ENGINE_KEYBOARD_CONTEXT_H */
