#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Visualizer
{
    public:
        Visualizer(int width = 800, int height = 600, float* bgColor = nullptr, float* oColor = nullptr);
        bool render(const float* center);
        void make_circle(const float* center, float* vertices, int* order);
    private:
        GLFWwindow* window;
        unsigned int VBO, VAO, EBO;
        unsigned int shaderProgram;
        float* backgroundColor;
        int precision = 50;
        float radius = 0.25f;
};

#endif