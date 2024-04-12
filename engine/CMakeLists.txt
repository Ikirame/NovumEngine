project(novum_engine)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)

add_subdirectory(opt/glad EXCLUDE_FROM_ALL)
add_subdirectory(opt/glfw EXCLUDE_FROM_ALL)

include_directories(include/core)

set(INCLUDE_FILES
        include/utility/FlatQueue.hpp
        include/platform/opengl/Context.h
        include/core/Window.h
        include/utility/Assertion.hpp
)

set(SRC_FILES
        src/platform/opengl/Context.cpp
        src/core/Window.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${INCLUDE_FILES})

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