/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/10/2024
 **/

#ifndef NOVUM_ENGINE_PLATFORM_OPENGL_WINDOW_H
#define NOVUM_ENGINE_PLATFORM_OPENGL_WINDOW_H

#include <memory>

#include "core/Window.h"
#include "platform/opengl/Context.h"

namespace novum_engine::platform::opengl
{
    class Window final : public core::Window
    {
    public:
        explicit Window(int width, int height, std::string const& title) noexcept;

        Window(Window const& rhs) noexcept = delete;
        Window(Window&& rhs) noexcept = delete;

        Window& operator=(Window  const& rhs) noexcept = delete;
        Window& operator=(Window&& rhs) noexcept = delete;

        void onUpdate() const noexcept override;

        [[nodiscard]] GLFWwindow* getNativeWindow() const noexcept { return m_glfw_window.get(); }

    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        struct GlfwWindowDeleter
        {
            void operator()(GLFWwindow* window) const noexcept
            {
                glfwDestroyWindow(window);
            }
        };

        std::unique_ptr<GLFWwindow, GlfwWindowDeleter> m_glfw_window;
    };
}

#endif /* NOVUM_ENGINE_PLATFORM_OPENGL_WINDOW_H */
