/**
 *  @file    EventDispatcher.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/01/2024
 **/

#ifndef NOVUM_ENGINE_EVENT_DISPATCHER_HPP
#define NOVUM_ENGINE_EVENT_DISPATCHER_HPP

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#include <functional>
#include <map>
#include <vector>

#include "Event.hpp"

namespace novum_engine::event
{
    template <typename T>
    class EventDispatcher
    {
        using SlotType = std::function<void(const Event<T>&)>;

    public:
        explicit EventDispatcher() noexcept = default;

        EventDispatcher(EventDispatcher const& rhs) noexcept = delete;
        EventDispatcher(EventDispatcher&& rhs) noexcept = delete;

        EventDispatcher& operator=(EventDispatcher const& rhs) noexcept = delete;
        EventDispatcher& operator=(EventDispatcher&& rhs) noexcept = delete;

        void subscribe(T type, const SlotType& func) noexcept
        {
            m_observers[type].push_back(func);
        }

        void post(Event<T>& event) noexcept
        {
            if (!m_observers.contains(event.type))
                return;

            for (auto&& observer : m_observers.at(event.type))
            {
                observer(event);
            }
        }

    private:
        std::map<T, std::vector<SlotType>> m_observers;
    };
}

#endif /* NOVUM_ENGINE_EVENT_DISPATCHER_HPP */
