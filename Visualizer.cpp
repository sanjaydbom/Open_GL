#include "Visualizer.h"
#include <stdexcept>

Visualizer::Visualizer(int width, int height)
{
    //Initialize glfw
    glfwInit();

    //tells us which version of glfw we are working with: 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create window
    window = glfwCreateWindow(width, height, "My OpenGL Window", NULL, NULL);
    //make sure window is created
    if(window == NULL){
        glfwTerminate();
        std::cout << "COOKEd";
        //throw std::system_error("Error initializing window. Check system configurations and libraries");
    }

    //idk just make the context current to make sure glfw operates on this window?
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Cooked";
        //throw std::system_error("Error initializing GLAD. Check system configurations and libraries");
    }
}

bool Visualizer::render()
{
    //std::cout << "Working\n";
    //check if window should be closed
    if(glfwWindowShouldClose(window))
    {
        glfwTerminate();
        return false;
    }
    //if window isn't going to close, render the window
    glfwPollEvents();

    glClearColor(0.2f,0.3f,0.3f,1.0f);//R,G,B,Alpha-how transparent it is
    glClear(GL_COLOR_BUFFER_BIT);

    //swap buffers
    glfwSwapBuffers(window);
    return true;
}