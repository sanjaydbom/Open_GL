#include "Visualizer.h"

int main(){
    float bgColor[] = {1.0,0.0,0.0,1.0};
    float oColor[] = {0.0,0.0,1.0,1.0};
    Visualizer GUI(800,600,bgColor, oColor);

    std::cout << "Starting rendering\n";
    while(GUI.render());
    std::cout << "Rendering done\n";
    return 0;
}