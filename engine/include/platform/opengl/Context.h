/**
 *  @file    Context.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    10/10/2022
 */

#ifndef NOVUM_ENGINE_CONTEXT_H
#define NOVUM_ENGINE_CONTEXT_H

#include "GLFW/glfw3.h"

namespace novum_engine::platform::opengl
{
    constexpr int opengl_version_major = 4;
    constexpr int opengl_version_minor = 3;

    class Context
    {
    public:
        Context() noexcept;

        GLFWwindow *window;
    };
}

#endif /* NOVUM_ENGINE_CONTEXT_H */
