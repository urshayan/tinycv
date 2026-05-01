#include <iostream>
#include "io/image_io.h"

// brighntess limit = -100 to +100
// contrast limit = 0.5 to 2
//  values other than that is nothing but pixel annihilation




using namespace tinycv;

int main()
{

    // not normalzied kernal
//    Kernal Blur({
//     {1, 1, 1},
//     {1, 1, 1},
//     {1, 1, 1}
// });

Kernal Blur({
    {1.0f/9, 1.0f/9, 1.0f/9},
    {1.0f/9, 1.0f/9, 1.0f/9},
    {1.0f/9, 1.0f/9, 1.0f/9}
});



    Image img = loadImage("mee.png"); 

    std::cout << "Loaded Image: " << img.width << " x " << img.height << "\n";
    
    Image result = Image::convolve(img,Blur);


    saveImage(result, "blur1.png");

    // Test 1: brightness increase
    //saveImage(img.brightnessAndcontrast(img, 1.0f, 50), "bright.png");

    // Test 2: contrast increase
    //saveImage(img.brightnessAndcontrast(img, 1.5f, 0), "contrast.png");

    // Test 3: darker + lower contrast
    //saveImage(img.brightnessAndcontrast(img, 0.7f, -40), "dark.png");

    std::cout << "Saved test images\n";

    return 0;
}