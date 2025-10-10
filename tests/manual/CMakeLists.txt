PROJECT(novum_engine_manual_tests)

set(TEST_INC_FILES
        include/TestApplication.h
)

set(TEST_SRC_FILES
        src/TestApplication.cpp
        src/main.cpp)

add_executable(${PROJECT_NAME}
        ${TEST_SRC_FILES}
        ${TEST_INC_FILES})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif ()

target_include_directories(${PROJECT_NAME}
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE imgui novum_engine)