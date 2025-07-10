cmake_minimum_required(VERSION 3.30)
project("atividade1")

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include
        C:/Libraries/GLFW/include
        ${CMAKE_SOURCE_DIR}
        ${GLFW_INCLUDE_DIRS}
)
link_directories(C:/Libraries/GLFW/lib-vc2022)

set(SOURCES
        src/main.cpp
        src/texture.cpp
        src/camera.cpp
        src/input.cpp
        src/render.cpp
        src/utils.cpp  
        src/planet.cpp
        src/globals.cpp
)

add_executable(atividade1 ${SOURCES})

file(COPY assets/texturas DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file (COPY assets/sound DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (WIN32)
        target_link_libraries(atividade1 glfw3 opengl32 gdi32 glu32)
else()
        find_package(OPEN_GL REQUIRED)
        find_package(GLU REQUIRED)
        find_package(PkgConfig REQUIRED)
        pkg_source_module(GLFW REQUIRED glfw3)

        include_directories(${GLFW_INCLUDE_DIRS})
        target_link_libraries(atividade1 ${OPEN_gl_LIBRARY} ${GLU_LIBRARY} ${GLFW_LIBRARIES})
endif()
