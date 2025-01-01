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
)

set(CORE_SRC_FILES
        src/core/Application.cpp
        src/core/Window.cpp
)

set(EVENT_INCLUDE_FILES
        include/event/Event.hpp
        include/event/EventDispatcher.hpp
        include/event/window/WindowClosedEvent.h
        include/event/window/WindowResizedEvent.h
        include/event/window/WindowEventType.h
)

set(OPENGL_GRAPHICS_API_INCLUDE_FILES
        include/graphics/api/opengl/OpenglGraphicsApi.h
)

set(OPENGL_GRAPHICS_API_SRC_FILES
        src/graphics/api/opengl/OpenglGraphicsApi.cpp
)

set(UTILITY_INCLUDE_FILES
        include/utility/Assertion.hpp
)

add_library(${PROJECT_NAME} STATIC
        ${CORE_SRC_FILES} ${OPENGL_GRAPHICS_API_SRC_FILES}
        ${CORE_INCLUDE_FILES} ${UTILITY_INCLUDE_FILES} ${OPENGL_GRAPHICS_API_INCLUDE_FILES} ${EVENT_INCLUDE_FILES})

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