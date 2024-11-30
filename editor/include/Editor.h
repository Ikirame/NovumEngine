/**
 *  @file    Editor.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/29/2024
 **/

#ifndef NOVUM_EDITOR_H
#define NOVUM_EDITOR_H

#include <core/Application.h>

namespace novum_editor
{
    class Editor final : public novum_engine::core::Application
    {
    public:
        Editor(Editor const& rhs) noexcept = delete;
        Editor(Editor&& rhs) noexcept = delete;

        Editor& operator=(Editor const& rhs) noexcept = delete;
        Editor& operator=(Editor&& rhs) noexcept = delete;

        static const Editor& getInstance()
        {
            static Editor instance;
            return instance;
        }

        void onUpdate() const noexcept override;

    private:
        explicit Editor() noexcept;
        ~Editor() noexcept override;
    };
};

#endif /* NOVUM_EDITOR_H */
