#pragma once
#include <vector>

  // GRAY-SCALE
    enum class GrayMethod{
        average,
        luminosity,
        lightness,
        redChannel
    };

namespace tinycv{

    // pixel memory representation
    // unsigned char is 8-bits => 1byte  
    struct Pixel{
        unsigned char r,g,b;
    };

    class Image{
        public:
            int width = 0;
            int height = 0;

            std::vector<Pixel> data;

            // constrcutors
            Image() = default;
            Image(int w, int h);

            // funtions
            Pixel& at(int x, int y);
            const Pixel& at(int x, int y)const;

            void fill(Pixel p);
            // funtion for gray scale, invertColor
           static Image grayscale(const Image& img, GrayMethod method);
           static Image invertColor(const Image& img);
           // To Be implemented!
           //static Image brightnessAndcontrast(const Image& img, alpha , beta);
           static Image brightnessAndcontrast(const Image& img, float alpha, int beta);
    };

}
 
 
/*

    Grayscale            => take average of the pixel ...or multiply with magic numbers...or the max - min / 2 method...
    InvertColors         => take individual pixel and subtract it from 255
    Brightness&Contrast  => output pixel  = alpha * (input pixel) + beta  .. where alpha=gain,contrast,value>1 means more contrast
                            and beta = bias,brightness,adding value makes it more bright and vice versa 

*/