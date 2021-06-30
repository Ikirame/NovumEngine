add_subdirectory(glad)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(glfw)
include_directories(glfw/include)

option(GLM_TEST_ENABLE OFF)

add_subdirectory(glm)
include_directories(glm)