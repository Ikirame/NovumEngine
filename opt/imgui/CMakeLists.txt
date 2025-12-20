project(imgui)

set(BACKEND_INC_FILES
        backends/imgui_impl_glfw.h
        backends/imgui_impl_opengl3.h
        backends/imgui_impl_opengl3_loader.h)

set(INC_FILES
        imconfig.h
        imgui.h
        imgui_internal.h
        imstb_rectpack.h
        imstb_textedit.h
        imstb_truetype.h)

set(BACKEND_SRC_FILES
        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_opengl3.cpp)

set(SRC_FILES
        imgui.cpp
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp)

add_library(${PROJECT_NAME} STATIC
        ${BACKEND_SRC_FILES} ${SRC_FILES}
        ${BACKEND_INC_FILES} ${INC_FILES})

target_include_directories(${PROJECT_NAME}
        PUBLIC ".")

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)