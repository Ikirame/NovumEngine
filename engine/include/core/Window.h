/**
 *  @file    Window.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/10/2024
 **/

#ifndef NOVUM_ENGINE_WINDOW_H
#define NOVUM_ENGINE_WINDOW_H

#include <iostream>
#include <memory>

#include "GLFW/glfw3.h"

namespace novum_engine::core
{
    class Window
    {
    public:
        explicit Window(int width = 1280, int height = 720, std::string const& title = "NovumEngine") noexcept;

        Window(Window const& rhs) noexcept = delete;
        Window(Window&& rhs) noexcept = delete;

        Window& operator=(Window const& rhs) noexcept = delete;
        Window& operator=(Window&& rhs) noexcept = delete;

        void render() const;

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

#endif /* NOVUM_ENGINE_WINDOW_H */
