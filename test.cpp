#include <iostream>
#include "io/image_io.h"

using namespace tinycv;

int main()
{
    Image img = loadImage("me.jpg");

    std::cout << "Loaded Image: " << img.width << " x " << img.height << "\n";
    
    // testing modifcation
    img.at(0,0) = {255,0,0};

    saveImage(img, "ouput.png");

    std::cout << "Saved output.png \n";

    return 0;
}