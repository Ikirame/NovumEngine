/**
 *  @file    Application.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_CORE_APPLICATION_H
#define NOVUM_ENGINE_CORE_APPLICATION_H

#include "core/Window.h"

namespace novum_engine::core
{
    class Application
    {
    public:
        explicit Application() noexcept = default;

        Application(Application const& rhs) noexcept = delete;
        Application(Application&& rhs) noexcept = delete;

        Application& operator=(Application const& rhs) noexcept = delete;
        Application& operator=(Application&& rhs) noexcept = delete;

        virtual ~Application() noexcept = default;

        virtual void onUpdate() const noexcept = 0;

        void run() const noexcept;

    protected:
        bool m_is_running{true};

        std::unique_ptr<Window> m_window
        {
            std::make_unique<Window>(800, 600, "NovumEngine")
        };
    };
}

#endif /* NOVUM_ENGINE_CORE_APPLICATION_H */
