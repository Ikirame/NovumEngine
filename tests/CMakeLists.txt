PROJECT(novum_engine_tests)

option(CATCH_INSTALL_DOCS OFF)
option(CATCH_INSTALL_EXTRAS OFF)
option(CATCH_BUILD_TESTING OFF)

add_subdirectory(opt/catch2 EXCLUDE_FROM_ALL)

set(TEST_FILES
        DemoTests.cpp
)

add_executable(${PROJECT_NAME} ${TEST_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2WithMain novum_engine)