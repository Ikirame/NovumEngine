/**
 *  @file    GraphicsBackend.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/18/2026
 **/

#ifndef NOVUM_ENGINE_GRAPHICS_BACKEND_H
#define NOVUM_ENGINE_GRAPHICS_BACKEND_H

#include <cstdint>

namespace novum_engine::graphics
{
    enum class GraphicsBackend : uint8_t
    {
        OpenGL
    };
}

#endif //NOVUM_ENGINE_GRAPHICS_BACKEND_H
