/**
 *  @file    Event.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_EVENT_HPP
#define NOVUM_ENGINE_EVENT_HPP

namespace novum_engine::event
{
    enum class EventType : uint32_t
    {
        // Window
        WindowClose = 0x0001,
        WindowResize = 0x0002
    };

    struct Event
    {
        explicit Event(const EventType type) noexcept : type(type), isHandled(false) {}
        virtual ~Event() = default;

        EventType type;
        bool isHandled;
    };
}

#endif /* NOVUM_ENGINE_EVENT_HPP */
