project(${CMAKE_PROJECT_NAME}_editor)

file(GLOB_RECURSE BUILD_SRC
	src/*.cpp)

file(GLOB_RECURSE BUILD_INC
	include/*.h
	include/*.hpp)

add_executable(${PROJECT_NAME}
		"${BUILD_SRC}"
		"${BUILD_INC}")

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE ${NOVUM_ENGINE_WIN_COMMON_FLAGS})
else()
	target_compile_options(${PROJECT_NAME} PRIVATE ${NOVUM_ENGINE_WIN_COMMON_FLAGS})
endif()

target_include_directories(${PROJECT_NAME}
		PRIVATE	"${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME})