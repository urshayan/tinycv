#pragma once
#include <vector>

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
    };

}