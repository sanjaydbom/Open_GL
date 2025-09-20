#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Visualizer
{
    public:
        Visualizer(int width = 800, int height = 600);
        bool render();
    private:
        GLFWwindow* window;
        unsigned int VBO, VAO;
        unsigned int shaderProgram;
};

#endif