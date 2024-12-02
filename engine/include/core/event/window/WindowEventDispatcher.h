/**
 *  @file    WindowEventDispatcher.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_EVENT_DISPATCHER_H
#define NOVUM_ENGINE_WINDOW_EVENT_DISPATCHER_H

#include "utility/event/EventDispatcher.hpp"

#include "WindowEventType.h"

class WindowEventDispatcher final : public novum_engine::utility::event::EventDispatcher<WindowEventType>
{
public:
    WindowEventDispatcher(WindowEventDispatcher const& rhs) noexcept = delete;
    WindowEventDispatcher(WindowEventDispatcher&& rhs) noexcept = delete;

    WindowEventDispatcher& operator=(WindowEventDispatcher const& rhs) noexcept = delete;
    WindowEventDispatcher& operator=(WindowEventDispatcher&& rhs) noexcept = delete;

    static WindowEventDispatcher& getInstance()
    {
        static WindowEventDispatcher instance;
        return instance;
    }

private:
    explicit WindowEventDispatcher() noexcept = default;
    ~WindowEventDispatcher() noexcept = default;
};

#endif /* NOVUM_ENGINE_WINDOW_EVENT_DISPATCHER_H */
