cmake_minimum_required(VERSION 3.16.8)

project("novum-engine"
		VERSION 1.0
		DESCRIPTION "Tiny OpenGL rendering engine"
		LANGUAGES CXX)

option(NOVUM_ENGINE_BUILD_TESTS "Build the tests project" ON)

add_subdirectory(engine)
add_subdirectory(editor)

if(${NOVUM_ENGINE_BUILD_TESTS})
	add_subdirectory(tests)
endif()