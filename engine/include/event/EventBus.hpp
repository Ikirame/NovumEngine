/**
 *  @file    EventBus.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/01/2024
 **/

#ifndef NOVUM_ENGINE_EVENT_BUS_HPP
#define NOVUM_ENGINE_EVENT_BUS_HPP

#include <functional>
#include <vector>

#include "Event.hpp"

namespace novum_engine::event
{
    class EventBus
    {
    public:
        explicit EventBus() noexcept = default;

        EventBus(EventBus const& rhs) noexcept = delete;
        EventBus(EventBus&& rhs) noexcept = delete;

        EventBus& operator=(EventBus const& rhs) noexcept = delete;
        EventBus& operator=(EventBus&& rhs) noexcept = delete;

        template <typename EventType, typename Fn>
        void subscribe(Fn&& fn) noexcept
        {
            static_assert(std::is_base_of_v<Event, EventType>, "EventType must derive from Event");

            auto callback = [f = std::forward<Fn>(fn)](Event& e)
            {
                f(static_cast<EventType&>(e));
            };

            m_listeners[EventType::getStaticType()].push_back(std::move(callback));
        }

        void publish(Event& event) const noexcept
        {
            if (!m_listeners.contains(event.getType()))
                return;

            for (auto&& listener : m_listeners.at(event.getType()))
            {
                listener(event);
                if (event.isHandled)
                {
                    break;
                }
            }
        }

    private:
        using EventCallback = std::function<void(Event&)>;

        std::unordered_map<EventType, std::vector<EventCallback> > m_listeners;
    };
}

#endif /* NOVUM_ENGINE_EVENT_BUS_HPP */
