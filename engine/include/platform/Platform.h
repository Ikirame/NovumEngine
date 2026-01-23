/**
 *  @file    Platform.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/12/2025
 **/

#ifndef NOVUM_ENGINE_PLATFORM_H
#define NOVUM_ENGINE_PLATFORM_H

#include <optional>
#include <variant>

#include "Window.h"
#include "graphics/GraphicsBackend.h"
#include "graphics/backend/opengl/OpenGLContext.h"
#include "utility/Assertion.hpp"
#include "utility/Helpers.hpp"

namespace novum_engine::platform
{
    class Platform
    {
    public:
        explicit Platform(graphics::GraphicsBackend graphicsBackend, event::EventBus& eventBus) noexcept;

        Platform(Platform const& rhs) noexcept = delete;
        Platform(Platform&& rhs) noexcept = delete;

        Platform& operator=(Platform const& rhs) noexcept = delete;
        Platform& operator=(Platform&& rhs) noexcept = delete;

        ~Platform() noexcept;

        [[nodiscard]] std::unique_ptr<Window> createWindow(const std::string& title, int width,
                                                           int height) const noexcept;

        template <typename T>
        [[nodiscard]] T& getGraphicsContext() noexcept
        {
            static_assert(
                utility::variant::variant_contains_v<T, GraphicsContextType>,
                "Requested type is not part of this context variant"
            );

            NOVUM_ENGINE_ASSERT(m_graphics_context.has_value(), "Context not initialized");
            NOVUM_ENGINE_ASSERT(std::holds_alternative<T>(*m_graphics_context), "Context does not hold requested type");

            return std::get<T>(*m_graphics_context);
        }

        void pollEvents() const noexcept;

    private:
        using GraphicsContextType = std::variant<graphics::backend::OpenGLContext>;

        event::EventBus& m_eventBus;

        std::optional<GraphicsContextType> m_graphics_context;
    };
}

#endif /* NOVUM_ENGINE_PLATFORM_H */
