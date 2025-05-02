PROJECT(novum_engine_manual_tests)

set(TEST_FILES
        main.cpp)

add_executable(${PROJECT_NAME} ${TEST_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE imgui novum_engine)