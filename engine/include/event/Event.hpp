/**
 *  @file    Event.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/01/2024
 **/

#ifndef NOVUM_ENGINE_EVENT_HPP
#define NOVUM_ENGINE_EVENT_HPP

namespace novum_engine::event
{
    template <typename T>
    struct Event
    {
        T type;

        explicit Event(T type) : type(type) {}

        virtual ~Event() = default;
    };
}

#endif /* NOVUM_ENGINE_EVENT_HPP */
