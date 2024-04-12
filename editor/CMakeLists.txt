project(novum_engine_editor)

set(SRC_FILES
        src/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE novum_engine)