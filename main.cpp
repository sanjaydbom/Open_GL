#include "Visualizer.h"

int main(){
    Visualizer GUI(800,600);

    std::cout << "Starting rendering\n";
    while(GUI.render());
    std::cout << "Rendering done\n";
    return 0;
}