set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	string(REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
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

file(GLOB_RECURSE BUILD_SRC
	src/*.cpp)

file(GLOB_RECURSE BUILD_INC
	inc/*.h
	inc/*.hpp)

add_library(${CMAKE_PROJECT_NAME} STATIC
		"${BUILD_SRC}"
		"${BUILD_INC}")

target_include_directories(${CMAKE_PROJECT_NAME}
		PUBLIC	"${CMAKE_CURRENT_SOURCE_DIR}/inc")

target_link_libraries(${CMAKE_PROJECT_NAME} glad glfw
		${GLFW_LIBRARIES})