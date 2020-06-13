cmake_minimum_required(VERSION 3.17)

project(NovumEngine
		VERSION 1.0
		DESCRIPTION "Tiny OpenGL rendering engine")

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

add_subdirectory(opt)

file(GLOB_RECURSE BUILD_SRC
	src/*.cpp)

file(GLOB_RECURSE BUILD_INC
	inc/*.h
	inc/*.hpp)

add_library(${PROJECT_NAME} STATIC
		"${BUILD_SRC}"
		"${BUILD_INC}")

target_link_libraries(${PROJECT_NAME} glad glm glfw
					  ${GLFW_LIBRARIES})