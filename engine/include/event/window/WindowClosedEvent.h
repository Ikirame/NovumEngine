/**
 *  @file    WindowClosedEvent.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_CLOSED_EVENT_H
#define NOVUM_ENGINE_WINDOW_CLOSED_EVENT_H

#include "WindowEventType.h"

#include "event/Event.hpp"

namespace novum_engine::event::window
{
    struct WindowClosedEvent final : Event<WindowEventType>
    {
        explicit WindowClosedEvent() noexcept : Event(WindowEventType::Closed)
        {
        }
    };
}

#endif /* NOVUM_ENGINE_WINDOW_CLOSED_EVENT_H */
