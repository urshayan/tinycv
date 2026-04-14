#define STB_IMAGE_IMPLEMENTATION
#include "../third_party/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../third_party/stb_image_write.h"

#include "image_io.h"

namespace tinycv{
    // funtion implementation
    Image loadImage(const char* filename){
        int w,h,channels;

        // from stb_image
        unsigned char* data = stbi_load(filename, &w, &h, &channels, 3);

        Image img(w,h);

        for (int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                int i = (y * w + x) * 3; // multiply by the number of channels!

                img.at(x,y) = {
                    data[i],
                    data[i+1],
                    data[i+2]
                };

            }
        }
        
        stbi_image_free(data);
        return img;

    }

    void saveImage(const Image& img, const char* filename){
        std::vector<unsigned char> raw;
        raw.reserve(img.width * img.height * 3);

        for (auto &p: img.data){
            raw.push_back(p.r);
            raw.push_back(p.g);
            raw.push_back(p.b);
        }

        // from stb_image_write
        stbi_write_png(
            filename,
            img.width,
            img.height,
            3,
            raw.data(),
            img.width * 3
        );

    }



}