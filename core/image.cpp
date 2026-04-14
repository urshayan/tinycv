#include "image.h"

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

}