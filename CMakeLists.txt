cmake_minimum_required(VERSION 3.16.8)

project("novum-engine"
		VERSION 1.0
		DESCRIPTION "Tiny OpenGL rendering engine"
		LANGUAGES C CXX)

option(${PROJECT_NAME}_BUILD_TESTS "Build the tests project" OFF)

add_subdirectory(opt EXCLUDE_FROM_ALL)

add_subdirectory(engine)
add_subdirectory(editor)

if({PROJECT_NAME}_BUILD_TESTS)
	add_subdirectory(tests)
endif()