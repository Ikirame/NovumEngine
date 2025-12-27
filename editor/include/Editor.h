/**
 *  @file    Editor.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/29/2024
 **/

#ifndef NOVUM_ENGINE_EDITOR_H
#define NOVUM_ENGINE_EDITOR_H

#include "core/Application.h"

namespace novum_engine::editor
{
    class Editor final : public core::Application<Editor>
    {
    public:
        Editor(Editor const& rhs) noexcept = delete;
        Editor(Editor&& rhs) noexcept = delete;

        Editor& operator=(Editor const& rhs) noexcept = delete;
        Editor& operator=(Editor&& rhs) noexcept = delete;

    private:
        friend class Application;

        explicit Editor() noexcept = default;

        static void onInit() noexcept;
        static void onUpdate() noexcept;
        static void onUpdateUI() noexcept;
        static void onDestroy() noexcept;
    };
};

#endif /* NOVUM_ENGINE_EDITOR_H */
