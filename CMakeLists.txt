cmake_minimum_required(VERSION 3.12.4)

project(NovumEngine
		VERSION 1.0
		DESCRIPTION "Tiny OpenGL rendering engine")

option(NOVUM_ENGINE_BUILD_EDITOR "Build the editor project" ON)

add_subdirectory(opt)

add_subdirectory(engine)

if(NOVUM_ENGINE_BUILD_EDITOR)
	add_subdirectory(editor)
endif()