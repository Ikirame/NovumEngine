/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_H
#define NOVUM_ENGINE_WINDOW_H

#include <memory>
#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace novum_engine::core
{
    class Window
    {
    public:
        explicit Window(int width, int height, const std::string& title) noexcept;

        Window(Window const& rhs) noexcept = delete;
        Window(Window&& rhs) noexcept = delete;

        Window& operator=(Window const& rhs) noexcept = delete;
        Window& operator=(Window&& rhs) noexcept = delete;

        void onUpdate() const noexcept;

        [[nodiscard]] GLFWwindow* getNativeWindow() const noexcept { return m_native_window.get(); }

    protected:
        struct GlfwWindowDeleter
        {
            void operator()(GLFWwindow* window) const noexcept
            {
                glfwDestroyWindow(window);
            }
        };

        std::unique_ptr<GLFWwindow, GlfwWindowDeleter> m_native_window;

    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void window_close_callback(GLFWwindow* window);
    };
}

#endif /* NOVUM_ENGINE_WINDOW_H */
