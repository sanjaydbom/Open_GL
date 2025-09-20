#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Visualizer
{
    public:
        Visualizer(int width = 800, int height = 600, float* bgColor = nullptr, float* oColor = nullptr);
        bool render(const float* vertices, const int size);
    private:
        GLFWwindow* window;
        unsigned int VBO, VAO;
        unsigned int shaderProgram;
        float* backgroundColor, objectColor;
};

#endif