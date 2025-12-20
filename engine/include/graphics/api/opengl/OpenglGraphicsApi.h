/**
 *  @file    OpenglGraphicsApi.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/30/2024
 **/

#ifndef NOVUM_ENGINE_OPENGL_GRAPHICS_API_H
#define NOVUM_ENGINE_OPENGL_GRAPHICS_API_H

namespace novum_engine::graphics::api::opengl
{
    class OpenglGraphicsApi
    {
    public:
        explicit OpenglGraphicsApi() noexcept;

        OpenglGraphicsApi(OpenglGraphicsApi const& rhs) noexcept = delete;
        OpenglGraphicsApi(OpenglGraphicsApi&& rhs) noexcept = delete;

        OpenglGraphicsApi& operator=(OpenglGraphicsApi const& rhs) noexcept = delete;
        OpenglGraphicsApi& operator=(OpenglGraphicsApi&& rhs) noexcept = delete;

        static void resizeViewport(int x, int y, int width, int height) noexcept;
        static void render() noexcept;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_GRAPHICS_API_H */
