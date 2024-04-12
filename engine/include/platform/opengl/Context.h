/**
 *  @file    Context.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    10/10/2022
 **/

#ifndef NOVUM_ENGINE_CONTEXT_H
#define NOVUM_ENGINE_CONTEXT_H

#include "core/Window.h"

namespace novum_engine::platform::opengl
{
    class Context
    {
    public:
        Context() noexcept;

        Context(Context const& rhs) noexcept = delete;
        Context(Context&& rhs) noexcept = delete;

        Context& operator=(Context const& rhs) noexcept = delete;
        Context& operator=(Context&& rhs) noexcept = delete;

        ~Context() noexcept;

        [[nodiscard]] const core::Window& getWindow() const noexcept
        {
            return *m_window;
        }

    private:
        std::unique_ptr<core::Window> m_window;

        static constexpr int opengl_version_major = 4;
        static constexpr int opengl_version_minor = 3;
    };
}

#endif /* NOVUM_ENGINE_CONTEXT_H */
