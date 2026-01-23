/**
 *  @file    OpenGLContext.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/18/2026
 **/

#ifndef NOVUM_ENGINE_OPENGL_CONTEXT_H
#define NOVUM_ENGINE_OPENGL_CONTEXT_H

namespace novum_engine::graphics::backend
{
    typedef void (*OpenGLApiProc)();
    typedef OpenGLApiProc (*OpenGLLoadFunc)(const char *name);

    struct OpenGLContext
    {
        OpenGLLoadFunc glLoadFunc;
    };
}

#endif /* NOVUM_ENGINE_OPENGL_CONTEXT_H */
