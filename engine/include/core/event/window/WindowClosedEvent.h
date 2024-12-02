/**
 *  @file    WindowClosedEvent.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_CLOSED_EVENT_H
#define NOVUM_ENGINE_WINDOW_CLOSED_EVENT_H

#include "utility/event/Event.hpp"

#include "WindowEventType.h"

namespace novum_engine::core::event
{
    struct WindowClosedEvent final : utility::event::Event<WindowEventType>
    {
        explicit WindowClosedEvent() noexcept : Event(WindowEventType::Closed) {}
    };
}

#endif /* NOVUM_ENGINE_WINDOW_CLOSED_EVENT_H */
