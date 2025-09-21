#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Visualizer
{
    public:
        Visualizer(int width = 800, int height = 600, float* bgColor = nullptr, float* oColor = nullptr, int m_precision = 50, int m_num_circles = 1);
        bool render(const float* centers);
        void make_circle(const float* center, float* vertices, int* order, int offset);
    private:
        GLFWwindow* window;
        unsigned int VBO, VAO, EBO;
        unsigned int shaderProgram;
        float* backgroundColor;
        int precision;
        int numCircles;
        float radius = 0.25f;
        GLint aspectRatioUniformLocation;
        float aspectRatio;
};

#endif