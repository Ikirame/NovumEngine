project(${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE BUILD_SRC
	src/*.cpp)

file(GLOB_RECURSE BUILD_INC
	include/*.h
	include/*.hpp)

add_library(${PROJECT_NAME} STATIC
		"${BUILD_SRC}"
		"${BUILD_INC}")

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
	if(NOT WIN32)
		set(GLAD_LIBRARIES dl)
	endif()
endif()

target_include_directories(${PROJECT_NAME}
		PUBLIC	"${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE glad glm glfw ${GLFW_LIBRARIES})