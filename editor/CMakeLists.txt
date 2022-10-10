project(novum_engine_editor)

file(GLOB_RECURSE BUILD_SRC
	src/main.cpp)

add_executable(${PROJECT_NAME} "${BUILD_SRC}")

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE novum_engine)