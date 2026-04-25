#include "image.h"
#include <algorithm>


// clamp funtion
inline unsigned char clamp(int v) {
    return static_cast<unsigned char>(v < 0 ? 0 : (v > 255 ? 255 : v));
}

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

    Image Image::brightnessAndcontrast(const Image& img, float alpha, int beta){

        Image out(img.width, img.height);

        for(int y = 0; y < img.height; y++){
            for (int x = 0; x < img.width; x++){
                auto p = img.at(x,y);
                
                int new_r = alpha * (p.r - 128) + beta;
                int new_g = alpha * (p.g - 128) + beta;
                int new_b = alpha * (p.b - 128) + beta;

                out.at(x,y) = {
                    
                    clamp(new_r),
                    clamp(new_g),
                    clamp(new_b)
                };

            }
        }
        return out;

    }

}
 