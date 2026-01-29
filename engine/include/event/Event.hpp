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
        WindowClose = 0x0001,
        WindowResize = 0x0002
    };

    struct Event
    {
        explicit Event() noexcept = default;
        virtual ~Event() = default;

        virtual EventType getType() const noexcept = 0;

        bool isHandled = false;
    };
}

#endif /* NOVUM_ENGINE_EVENT_HPP */
