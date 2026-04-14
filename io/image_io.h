#pragma once
#include "../core/image.h"

namespace tinycv{
    // io-funtions
    Image loadImage(const char* filename);
    void saveImage(const Image& img, const char* filename);
}