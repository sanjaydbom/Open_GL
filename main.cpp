#include "Visualizer.h"

int main(){
    float bgColor[] = {0.0,0.0,0.0,1.0};
    float oColor[] = {1.0,1.0,1.0,1.0};
    Visualizer GUI(800,600,bgColor, oColor, 50, 2);

    float center[] = {
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f // Top-Right vertex
    };


    std::cout << "Starting rendering\n";
    while(GUI.render(center));
    std::cout << "Rendering done\n";
    return 0;
}