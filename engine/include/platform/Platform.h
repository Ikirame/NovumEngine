/**
 *  @file    Platform.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#ifndef NOVUM_ENGINE_PLATFORM_H
#define NOVUM_ENGINE_PLATFORM_H

#include "Window.h"

namespace novum_engine::platform
{
    class Platform
    {
    public:
        Platform(Platform const& rhs) noexcept = delete;
        Platform(Platform&& rhs) noexcept = delete;

        Platform& operator=(Platform const& rhs) noexcept = delete;
        Platform& operator=(Platform&& rhs) noexcept = delete;

        static Platform& getInstance()
        {
            static Platform instance;
            return instance;
        }

        [[nodiscard]] std::unique_ptr<core::Window> createWindow() const noexcept;

        void pollEvents() const noexcept;

    private:
        Platform() noexcept;
        ~Platform() noexcept;

        bool m_initialized = false;
    };
}

#endif /* NOVUM_ENGINE_PLATFORM_H */
