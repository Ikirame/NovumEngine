/**
 *  @file    Platform.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#ifndef NOVUM_ENGINE_PLATFORM_H
#define NOVUM_ENGINE_PLATFORM_H

#include "Window.h"
#include "devices/KeyboardDevice.h"
#include "devices/MouseDevice.h"
#include "graphics/backend/opengl/OpenGLContext.h"
#include "input/InputContext.h"
#include "utility/Assertion.hpp"

namespace novum_engine::platform
{
    class Platform
    {
    public:
        explicit Platform(event::EventBus& eventBus) noexcept;

        Platform(Platform const& rhs) noexcept = delete;
        Platform(Platform&& rhs) noexcept = delete;

        Platform& operator=(Platform const& rhs) noexcept = delete;
        Platform& operator=(Platform&& rhs) noexcept = delete;

        ~Platform() noexcept;

        [[nodiscard]] std::unique_ptr<Window> createWindow(const std::string& title, int width,
                                                           int height) const noexcept;

        [[nodiscard]] graphics::backend::OpenGLContext getGraphicsContext() const noexcept;

        [[nodiscard]] input::InputContext getInputContext(const Window& window) const noexcept;

        void pollEvents() const noexcept;

    private:
        event::EventBus& m_eventBus;

        graphics::backend::OpenGLContext m_graphics_context;

        devices::KeyboardDevice m_keyboard_device;
        devices::MouseDevice m_mouse_device;
    };
}

#endif /* NOVUM_ENGINE_PLATFORM_H */
