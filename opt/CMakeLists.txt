add_subdirectory(glad)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(glfw)

option(GLM_TEST_ENABLE OFF)

add_subdirectory(glm)