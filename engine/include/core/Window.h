/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_CORE_WINDOW_H
#define NOVUM_ENGINE_CORE_WINDOW_H

namespace novum_engine::core
{
    class Window
    {
    public:
        explicit Window() noexcept = default;

        Window(Window const& rhs) noexcept = delete;
        Window(Window&& rhs) noexcept = delete;

        Window& operator=(Window const& rhs) noexcept = delete;
        Window& operator=(Window&& rhs) noexcept = delete;

        virtual ~Window() = default;

        virtual void onUpdate() const noexcept = 0;
    };
}

#endif /* NOVUM_ENGINE_CORE_WINDOW_H */
