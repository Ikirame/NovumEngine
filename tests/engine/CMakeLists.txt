PROJECT(${CMAKE_PROJECT_NAME}_tests)

file(GLOB_RECURSE BUILD_SRC
        src/*.cpp)

add_executable(${PROJECT_NAME}
        ${BUILD_SRC})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /std:c++17)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c++17)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2 ${CMAKE_PROJECT_NAME})