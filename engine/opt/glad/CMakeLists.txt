project(glad)

add_library(${PROJECT_NAME} STATIC
        src/gl.c)

target_include_directories(${PROJECT_NAME}
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")