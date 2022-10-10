project(novum_engine)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

option(GLM_TEST_ENABLE OFF)

add_subdirectory(opt/glad EXCLUDE_FROM_ALL)
add_subdirectory(opt/glfw EXCLUDE_FROM_ALL)
add_subdirectory(opt/glm EXCLUDE_FROM_ALL)

file(GLOB_RECURSE BUILD_INC
		include/Core.hpp
		include/utility/FlatQueue.hpp)

add_library(${PROJECT_NAME} STATIC "${BUILD_INC}")

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
	if(NOT WIN32)
		set(GLAD_LIBRARIES dl)
	endif()
endif()

# Todo: To Remove after adding the first ".cpp" file
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME}
		PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE glad glm glfw ${GLFW_LIBRARIES})