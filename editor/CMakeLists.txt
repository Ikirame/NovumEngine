project(novum_engine_editor)

set(INC_FILES
        include/Editor.h)

set(SRC_FILES
        src/main.cpp
        src/Editor.cpp)

add_executable(${PROJECT_NAME}
        ${SRC_FILES}
        ${INC_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif ()

target_include_directories(${PROJECT_NAME}
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE novum_engine imgui)