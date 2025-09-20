#include "Visualizer.h"

int main(){
    float bgColor[] = {0.0,0.0,0.0,1.0};
    float oColor[] = {1.0,1.0,1.0,1.0};
    Visualizer GUI(800,600,bgColor, oColor);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // Bottom-left vertex
        0.5f, -0.5f, 0.0f, // Bottom-right vertex
        0.0f,  0.5f, 0.0f // Top-middle vertex
    };

    std::cout << "Starting rendering\n";
    while(GUI.render(vertices, 9 * sizeof(float))){
        vertices[0] += 0.001f;
        vertices[3] += 0.001f;
        vertices[6] += 0.001f;
    }
    std::cout << "Rendering done\n";
    return 0;
}