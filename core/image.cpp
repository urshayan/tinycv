#include "image.h"
#include <algorithm>


namespace tinycv{

    // constructor
    Image::Image(int w, int h)
    {
        width = w;
        height = h;
        data.resize(w * h);
    }

    // funtion implementation
    Pixel& Image::at(int x, int y)
    {
        return data[y * width + x];
    }

    const Pixel& Image::at(int x, int y)const{
        return data[y * width + x];
    }

    void Image::fill(Pixel p)
    {
        for (auto &pixel: data){
            pixel = p;
        }
    }

       // gray-scale 
    Image Image::grayscale(const Image& img, GrayMethod method){
        Image out(img.width, img.height);

        for(int y = 0 ; y < img.height; y++){
            for (int x = 0; x < img.width; x++){
                auto p = img.at(x,y);
                unsigned char gray;

                switch(method){
                    case GrayMethod::average:
                        gray = (p.r + p.g + p.b) / 3;
                        break;
                    
                    case GrayMethod::luminosity:
                        gray = static_cast<unsigned char>(0.299 * p.r + 0.587 * p.g + 0.114 * p.b);
                        break;
                    
                    case GrayMethod::lightness:
                        gray = (std::max({p.r , p.g , p.b}) + std::min({p.r , p.g , p.b})) / 2;
                        break;
                    
                    case GrayMethod::redChannel:
                        gray = p.r;
                        break;
                }

                out.at(x,y) = {gray,gray,gray};


            }

        }
        return out;
    }
    // invert color
    Image Image::invertColor(const Image& img){
        Image out(img.width,img.height);
        for(int y = 0; y < img.height; y++){
            for (int x = 0; x < img.width; x++){
                auto p = img.at(x,y);
                // unsigned char new_r;
                // unsigned char new_g;
                // unsigned char new_b;

                // new_r = 255 - p.r;
                // new_g = 255 - p.g;
                // new_b = 255 - p.b;
                // we can simplify it by

                out.at(x,y) = {
                    (unsigned char)(255 - p.r),
                    (unsigned char)(255 - p.g),
                    (unsigned char)(255 - p.b)                };
            }
        }
        return out;
    }
}
 