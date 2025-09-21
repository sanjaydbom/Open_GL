#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Visualizer
{
    public:
        Visualizer(int width = 800, int height = 600, float* bgColor = nullptr, float* oColor = nullptr, int m_precision = 50, int m_num_circles = 1, std::string title = "My OpenGL Window");
        bool render(const float* centers, const float* radii);
    private:
        void make_circle(const float* center, float* vertices, int* order, const float radius, const int offset);

        GLFWwindow* window;
        unsigned int VBO, VAO, EBO;
        unsigned int shaderProgram;
        float* backgroundColor;
        int precision;
        int numCircles;
        GLint aspectRatioUniformLocation;
        float aspectRatio;
};

#endif