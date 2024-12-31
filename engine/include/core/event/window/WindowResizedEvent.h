/**
 *  @file    WindowResizedEvent.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/24/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_RESIZED_EVENT_H
#define NOVUM_ENGINE_WINDOW_RESIZED_EVENT_H

#include "WindowEventType.h"

#include "utility/event/Event.hpp"

namespace novum_engine::core::event::window
{
    struct WindowResizedEvent final : utility::event::Event<WindowEventType>
    {
        explicit WindowResizedEvent(const int& width, const int& height) noexcept : Event(WindowEventType::Resized)
        {
            m_width = width;
            m_height = height;
        }

        [[nodiscard]] const int& width() const noexcept { return m_width; }
        [[nodiscard]] const int& height() const noexcept { return m_height; }

    private:
        int m_width, m_height;
    };
}

#endif /* NOVUM_ENGINE_WINDOW_RESIZED_EVENT_H */
