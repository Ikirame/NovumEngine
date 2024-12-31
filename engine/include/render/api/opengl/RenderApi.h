/**
 *  @file    RenderApi.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#ifndef NOVUM_ENGINE_OPENGL_RENDER_API_H
#define NOVUM_ENGINE_OPENGL_RENDER_API_H

namespace novum_engine::render::api::opengl
{
    class RenderApi
    {
    public:
        explicit RenderApi() noexcept;

        RenderApi(RenderApi const& rhs) noexcept = delete;
        RenderApi(RenderApi&& rhs) noexcept = delete;

        RenderApi& operator=(RenderApi const& rhs) noexcept = delete;
        RenderApi& operator=(RenderApi&& rhs) noexcept = delete;

        static void resizeViewport(int x, int y, int width, int height) noexcept;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_RENDER_API_H */
