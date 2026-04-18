#include <iostream>
#include "io/image_io.h"

using namespace tinycv;

int main()
{
    Image img = loadImage("meen.png");

    std::cout << "Loaded Image: " << img.width << " x " << img.height << "\n";
    
    // testing modifcation
    saveImage(img.invertColor(img), "invert.png");

    std::cout << "Saved invert.png \n";

    return 0;
}