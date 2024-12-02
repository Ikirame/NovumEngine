project(novum_engine)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)

add_subdirectory(opt/glad EXCLUDE_FROM_ALL)
add_subdirectory(opt/glfw EXCLUDE_FROM_ALL)

include_directories(include/core)

set(CORE_INCLUDE_FILES
        include/core/Application.h
        include/core/Window.h
        include/core/event/window/WindowClosedEvent.h
        include/core/event/window/WindowEventType.h
        include/core/event/window/WindowEventDispatcher.h
)

set(CORE_SRC_FILES
        src/core/Application.cpp
        src/core/Window.cpp
)

set(OPENGL_PLATFORM_INCLUDE_FILES
        include/platform/opengl/Context.h
        include/platform/opengl/graphics/VertexBufferObject.h
        include/platform/opengl/graphics/VertexArrayObject.h
)

set(OPENGL_PLATFORM_SRC_FILES
        src/platform/opengl/graphics/VertexBufferObject.cpp
        src/platform/opengl/graphics/VertexArrayObject.cpp
)

set(UTILITY_INCLUDE_FILES
        include/utility/Assertion.hpp
        include/utility/FlatQueue.hpp
        include/utility/event/EventDispatcher.hpp
        include/utility/event/Event.hpp
)

add_library(${PROJECT_NAME} STATIC
        ${CORE_SRC_FILES} ${OPENGL_PLATFORM_SRC_FILES}
        ${CORE_INCLUDE_FILES} ${OPENGL_PLATFORM_INCLUDE_FILES} ${UTILITY_INCLUDE_FILES})

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

target_link_libraries(${PROJECT_NAME} PUBLIC glad glfw)