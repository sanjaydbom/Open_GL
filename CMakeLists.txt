cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp glad.c Visualizer.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    # This line is for GLAD and KHR
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries
    # This line is for GLFW
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glfw/include
)

target_link_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/build/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw3
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreFoundation"
    "-framework Carbon"
)