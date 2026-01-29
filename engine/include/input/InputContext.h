/**
 *  @file    InputContext.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/26/2026
 **/

#ifndef NOVUM_ENGINE_INPUT_CONTEXT_H
#define NOVUM_ENGINE_INPUT_CONTEXT_H

#include "KeyboardContext.h"
#include "MouseContext.h"

namespace novum_engine::input
{
    struct InputContext
    {
        KeyboardContext keyboardContext;
        MouseContext mouseContext;
    };
}

#endif /* NOVUM_ENGINE_INPUT_CONTEXT_H */