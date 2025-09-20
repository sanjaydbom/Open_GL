#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Visualizer
{
    public:
        Visualizer(int width = 800, int height = 600, float r = 0.2, float g = 0.3, float b = 0.3, float alpha = 1.0);
        bool render();
    private:
        GLFWwindow* window;
        unsigned int VBO, VAO;
        unsigned int shaderProgram;
        float backgroundColor[4];
};

#endif