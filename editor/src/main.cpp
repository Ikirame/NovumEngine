#include <iostream>

#include "glad/gl.h"

#include "platform/opengl/Context.h"

int	main()
{
    const novum_engine::platform::opengl::Context context;

    std::cout << "Editor launched successfully" << std::endl;
    std::cout << "Press any key to continue ..." << std::endl;

    glfwSetInputMode(context.window, GLFW_STICKY_KEYS, GL_TRUE);

    while(glfwGetKey(context.window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(context.window) == 0)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(context.window);
        glfwPollEvents();
    }

	return 0;
}