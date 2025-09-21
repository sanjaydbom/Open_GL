#include "Visualizer.h"

int main(){
    float bgColor[] = {0.0,0.0,0.0,1.0};
    float oColor[] = {1.0,1.0,1.0,1.0};
    Visualizer GUI(800,600,bgColor, oColor, 50, 2);

    const float center[] = {
        0.0f, 0.0f, 0.0f, //center 1
        0.35f, 0.0f, 0.0f //center 2
    };
    const float radii[] = {
        0.25f,
        0.10f
    };


    std::cout << "Starting rendering\n";
    while(GUI.render(center, radii));
    std::cout << "Rendering done\n";
    return 0;
}