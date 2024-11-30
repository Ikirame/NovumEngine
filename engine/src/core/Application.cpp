/**
 *  @file    Application.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include "Application.h"

void novum_engine::core::Application::run() const noexcept
{
    while (m_is_running)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        onUpdate();

        glfwSwapBuffers(m_window->getNativeWindow());
        glfwPollEvents();
    }
}
