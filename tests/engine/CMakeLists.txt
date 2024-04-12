PROJECT(novum_engine_tests)

set(TEST_FILES
        src/FlatQueueTests.cpp
)

add_executable(${PROJECT_NAME} ${TEST_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2WithMain novum_engine)