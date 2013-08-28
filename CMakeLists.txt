cmake_minimum_required(VERSION 2.8)

project(GLplaying)

set(SOURCE_DIR "src")

set(CMAKE_MODULE_PATH "/usr/local/share/Logger/;/usr/local/share/SFML/cmake/Modules/;${CMAKE_MODULE_PATH}")

set(EXECUTABLE_NAME "GLplaying")

add_executable(${EXECUTABLE_NAME} 
                ${SOURCE_DIR}/Cube.cpp
                ${SOURCE_DIR}/main.cpp)

find_package(SFML 2 REQUIRED graphics window system)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

find_package(OpenGL REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})

find_package(Logger REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} Logger)
