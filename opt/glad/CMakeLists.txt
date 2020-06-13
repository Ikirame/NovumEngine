project(glad)

file(GLOB_RECURSE BUILD_SRC
	src/*.c)

file(GLOB_RECURSE BUILD_INC
	include/*.h)

add_library(${PROJECT_NAME} STATIC
		"${BUILD_SRC}"
		"${BUILD_INC}")

target_include_directories(${PROJECT_NAME}
	PUBLIC	"${CMAKE_CURRENT_SOURCE_DIR}/include")