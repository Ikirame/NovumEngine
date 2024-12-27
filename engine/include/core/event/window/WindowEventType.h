/**
 *  @file    WindowEventType.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_EVENT_TYPE_H
#define NOVUM_ENGINE_WINDOW_EVENT_TYPE_H

namespace novum_engine::core::event::window
{
    enum class WindowEventType
    {
        Closed,
        Resized
    };
}

#endif /* NOVUM_ENGINE_WINDOW_EVENT_TYPE_H */
