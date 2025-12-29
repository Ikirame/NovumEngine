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
        using EventCallback = std::function<void(const Event&)>;

    public:
        explicit EventBus() noexcept = default;

        EventBus(EventBus const& rhs) noexcept = delete;
        EventBus(EventBus&& rhs) noexcept = delete;

        EventBus& operator=(EventBus const& rhs) noexcept = delete;
        EventBus& operator=(EventBus&& rhs) noexcept = delete;

        template <typename Fn>
        void subscribe(const EventType eventType, Fn&& fn) noexcept
        {
            auto wrapper = [f = std::forward<Fn>(fn)](const Event& e)
            {
                f(static_cast<const Event&>(e));
            };

            m_listeners[eventType].push_back(std::move(wrapper));
        }

        void publish(const Event& event) const noexcept
        {
            if (!m_listeners.contains(event.type))
                return;

            for (auto&& listener : m_listeners.at(event.type))
            {
                listener(event);
                if (event.isHandled)
                {
                    break;
                }
            }
        }

    private:
        std::unordered_map<EventType, std::vector<EventCallback> > m_listeners;
    };
}

#endif /* NOVUM_ENGINE_EVENT_BUS_HPP */
