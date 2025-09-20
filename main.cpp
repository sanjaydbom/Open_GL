#include "Visualizer.h"

int main(){
    Visualizer GUI(800,600,1.0,0.0,0.0,1.0);

    std::cout << "Starting rendering\n";
    while(GUI.render());
    std::cout << "Rendering done\n";
    return 0;
}