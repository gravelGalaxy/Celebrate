#pragma once

#include <stdexcept>
#include <vector>
#include "lodepng.h"

class Image {
public:
    enum ImageFormat {
        IMAGE_GREY = 0x0000,    // 灰度图像
        IMAGE_RGB,                // 彩色RGB图像
        IMAGE_BGR,                // 彩色BGR图像
        IMAGE_RGBA,                // 彩色RGBA图像
        IMAGE_BGRA                // 彩色BGRA图像
    };

    Image() = default;

    Image(std::string &filename, ImageFormat = IMAGE_GREY) { imread(filename); }

    const unsigned char& operator[](int i) const;

    virtual ~Image() = default;

    void imread(std::string &filename);

    std::pair<unsigned, unsigned> size() const;

    void encode(unsigned width, unsigned height);

    void convert(LodePNGColorType type);

    bool empty() const;

private:
    ImageFormat format_ = IMAGE_GREY;
    unsigned height_ = 0;
    unsigned width_ = 0;
    // the range of the unsigned char data type ranges from 0 ~ 255
    std::vector<unsigned char> pBuffer_{};
};


