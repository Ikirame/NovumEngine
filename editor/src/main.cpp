/**
 *  @file    main.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    11/30/2024
 **/

#include "Editor.h"

int main()
{
    const novum_editor::Editor& editor = novum_editor::Editor::getInstance();
    editor.run();

    return 0;
}

