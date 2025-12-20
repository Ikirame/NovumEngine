project(novum_engine)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)

include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.x)
FetchContent_MakeAvailable(spdlog)

add_subdirectory(opt/glad EXCLUDE_FROM_ALL)

set(CORE_INCLUDE_FILES
        include/core/Application.h
        include/core/Application.inl)

set(CORE_SRC_FILES )

set(PLATFORM_INCLUDE_FILES
        include/platform/Platform.h
        include/platform/Window.h)

set(PLATFORM_SRC_FILES
        src/platform/glfw/GlfwPlatform.cpp
        src/platform/glfw/GlfwWindow.cpp)

set(EVENT_INCLUDE_FILES
        include/event/Event.hpp
        include/event/EventDispatcher.hpp
        include/event/window/WindowEvent.h)

set(OPENGL_GRAPHICS_API_INCLUDE_FILES
        include/graphics/api/opengl/OpenglGraphicsApi.h)

set(OPENGL_GRAPHICS_API_SRC_FILES
        src/graphics/api/opengl/OpenglGraphicsApi.cpp)

set(UTILITY_INCLUDE_FILES
        include/utility/Assertion.hpp
        include/utility/Logger.h)

set(UTILITY_SRC_FILES
        src/utility/Logger.cpp)

add_library(${PROJECT_NAME} STATIC
        ${CORE_SRC_FILES} ${PLATFORM_SRC_FILES} ${OPENGL_GRAPHICS_API_SRC_FILES} ${UTILITY_SRC_FILES}
        ${CORE_INCLUDE_FILES} ${PLATFORM_INCLUDE_FILES} ${UTILITY_INCLUDE_FILES} ${OPENGL_GRAPHICS_API_INCLUDE_FILES} ${EVENT_INCLUDE_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++20)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++20)
    if (NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif ()
endif ()

target_include_directories(${PROJECT_NAME}
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw spdlog::spdlog)

target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:NOVUM_ENGINE_DEBUG=1>)