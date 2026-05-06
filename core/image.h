#pragma once
#include <vector>
#include <initializer_list>


  // GRAY-SCALE
    enum class GrayMethod{
        average,
        luminosity,
        lightness,
        redChannel
    };

namespace tinycv{

    // TODO: add normalization to the kernal and also make pre-built kernals and a kernal generator
   struct Kernal{
        int k_width, k_height;
        std::vector<std::vector<float>> k_data;

        Kernal(std::initializer_list<std::initializer_list<float>> mat){
            k_height = mat.size();
            k_width = mat.begin()->size();

            k_data.resize(k_height, std::vector<float>(k_width));

            int y = 0;

            for(auto &row : mat){
                int x = 0;
                for (auto v : row){
                    k_data[y][x++] = v;
                }
                y++;
            }

        }
        

   };


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
           static Image convolve(const Image& img, const Kernal& kernal);
    };

}
 
 
/*

    Grayscale            => take average of the pixel ...or multiply with magic numbers...or the max - min / 2 method...
    InvertColors         => take individual pixel and subtract it from 255
    Brightness&Contrast  => output pixel  = alpha * (input pixel) + beta  .. where alpha=gain,contrast,value>1 means more contrast
                            and beta = bias,brightness,adding value makes it more bright and vice versa 

*/