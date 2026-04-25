# 🚀 TinyCV

*A lightweight C++ computer vision library for learning, building, and
experimenting.*

------------------------------------------------------------------------

## 🌟 Overview

**TinyCV** is a minimal yet powerful computer vision library built from
scratch in C++.\
It's designed for developers who want to **understand how image
processing works under the hood** instead of relying on heavy
frameworks.

------------------------------------------------------------------------

## ✨ Features

-   📸 Image loading & saving (via stb_image)
-   🎨 Basic image processing:
    -   Brightness adjustment
    -   Contrast control
    -   Grayscale conversion
    -   Color inversion
-   ⚡ Lightweight and fast
-   🧱 Modular design for easy extension
-   🧠 Built for learning + experimentation

------------------------------------------------------------------------

## 📦 Installation

### 1. Clone the repository

``` bash
git clone https://github.com/urshayan/tinycv.git
cd tinycv
```

### 2. Build

``` bash
g++ main.cpp -o tinycv
```

------------------------------------------------------------------------

## 🚀 Usage

``` cpp
#include <iostream>
#include "io/image_io.h"

using namespace tinycv;

int main()
{
    Image img = loadImage("test.png");

    std::cout << "Loaded Image: "
              << img.width << " x " << img.height << "\n";

    Image result = img.brightnessAndcontrast(img, 30, 10);

    saveImage(result, "output.png");

    std::cout << "Saved output.png\n";

    return 0;
}
```

------------------------------------------------------------------------

## 🧩 Project Structure

    tinycv/
    │── io/
    │── core/
    │── filters/
    │── main.cpp
    │── stb_image.h
    │── stb_image_write.h

------------------------------------------------------------------------

## 🛠️ Roadmap

-   Phase 1: Basic operations ✅
-   Phase 2: Convolution filters 🚧
-   Phase 3: Advanced CV features 🔥

------------------------------------------------------------------------

## 🤝 Contributing

Pull requests are welcome!

------------------------------------------------------------------------

## 📜 License

MIT License

------------------------------------------------------------------------

## 👤 Author

Shayan Ijaz
