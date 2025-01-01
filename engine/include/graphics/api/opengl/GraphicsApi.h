/**
 *  @file    GraphicsApi.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#ifndef NOVUM_ENGINE_OPENGL_GRAPHICS_API_H
#define NOVUM_ENGINE_OPENGL_GRAPHICS_API_H

namespace novum_engine::graphics::api::opengl
{
    class GraphicsApi
    {
    public:
        explicit GraphicsApi() noexcept;

        GraphicsApi(GraphicsApi const& rhs) noexcept = delete;
        GraphicsApi(GraphicsApi&& rhs) noexcept = delete;

        GraphicsApi& operator=(GraphicsApi const& rhs) noexcept = delete;
        GraphicsApi& operator=(GraphicsApi&& rhs) noexcept = delete;

        static void resizeViewport(int x, int y, int width, int height) noexcept;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_GRAPHICS_API_H */
