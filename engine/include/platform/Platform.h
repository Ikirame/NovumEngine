/**
 *  @file    Platform.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#ifndef NOVUM_ENGINE_PLATFORM_H
#define NOVUM_ENGINE_PLATFORM_H

#include "Window.h"

#include "graphics/backend/opengl/OpenGLBackend.h"

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

        [[nodiscard]] std::unique_ptr<Window> createWindow() const noexcept;
        [[nodiscard]] std::unique_ptr<graphics::backend::opengl::OpenGLBackend> createGraphicsBackend() const noexcept;

        void pollEvents() const noexcept;

    private:
        Platform() noexcept;
        ~Platform() noexcept;
    };
}

#endif /* NOVUM_ENGINE_PLATFORM_H */
