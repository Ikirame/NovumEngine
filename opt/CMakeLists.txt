option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

option(GLM_TEST_ENABLE OFF)

add_subdirectory(glad EXCLUDE_FROM_ALL)
add_subdirectory(glfw EXCLUDE_FROM_ALL)
add_subdirectory(glm EXCLUDE_FROM_ALL)
add_subdirectory(catch2 EXCLUDE_FROM_ALL)