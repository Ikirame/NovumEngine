PROJECT(${CMAKE_PROJECT_NAME}_tests)

file(GLOB_RECURSE BUILD_SRC
        src/*.cpp)

add_executable(${PROJECT_NAME}
        ${BUILD_SRC})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE ${NOVUM_ENGINE_WIN_COMMON_FLAGS} /std:c++17)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE ${NOVUM_ENGINE_UNIX_COMMON_FLAGS} -std=c++17)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2 ${CMAKE_PROJECT_NAME})