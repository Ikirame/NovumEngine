/**
 *  @file    Context.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    10/10/2022
 */

#include "platform/opengl/Context.h"

novum_engine::platform::opengl::Context::Context() noexcept {
    const auto glfw_ret = glfwInit();
    assert(glfw_ret && "GLFW initialization failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_version_minor);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif /* __APPLE__ */

    window = glfwCreateWindow(800, 600, "TEST", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        assert(window && "GLFW window creation failed");
    }

    glfwMakeContextCurrent(window);

    const auto glad_ret = gladLoadGL(glfwGetProcAddress);
    if (!glad_ret) {
        glfwTerminate();
        assert(glad_ret && "GLAD initialization failed");
    }

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " <<
              glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n' << std::endl;
#endif /* NDEBUG */
}