/**
 *  @file    WindowEvent.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_EVENT_H
#define NOVUM_ENGINE_WINDOW_EVENT_H

#include "event/Event.hpp"

namespace novum_engine::event::window
{
    struct WindowClosedEvent : Event
    {
        WindowClosedEvent() noexcept = default; /*: Event(EventType::WindowClose) {}*/

        static constexpr EventType getStaticType() noexcept { return EventType::WindowClose; }

        EventType getType() const noexcept override { return getStaticType(); }
    };

    struct WindowResizedEvent : Event
    {
        explicit WindowResizedEvent(const int& width, const int& height) noexcept : m_width(width), m_height(height) {}

        [[nodiscard]] const int& width() const noexcept { return m_width; }
        [[nodiscard]] const int& height() const noexcept { return m_height; }

        static constexpr EventType getStaticType() noexcept { return EventType::WindowResize; }

        EventType getType() const noexcept override { return getStaticType(); }

    private:
        int m_width, m_height;
    };
}

#endif /* NOVUM_ENGINE_WINDOW_EVENT_H */
