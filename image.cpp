//
// Created by gravelgalaxy on 23-11-15.
//

#include "image.h"
#include <fstream>
#include <iostream>
#include "lodepng.h"

using namespace std;

void Image::imread(std::string &filename) {
    unsigned error = lodepng::decode(pBuffer_, width_, height_, filename, LCT_GREY, 8);
    if (error) {
        pBuffer_.clear();
        cout << "decoder error" << error << ": " << lodepng_error_text(error) << std::endl;
    } else {
        cout << "the width of the png file is: " << width_ << ";" << "height is:" << height_ << endl;
    }
}

bool Image::empty() const{
    return pBuffer_.empty();
}

const unsigned char &Image::operator[](int i) const {
    if (i < 0 || i > pBuffer_.size() - 1) {
        throw std::invalid_argument("the index of the Image gaven " + to_string(i));
    }
    return pBuffer_[i];
}

std::pair<unsigned, unsigned> Image::size() const{
    return {width_, height_};
}

void Image::encode(unsigned int width, unsigned int height) {
    vector<unsigned char> temp;
    temp.swap(pBuffer_);
    unsigned error = lodepng::encode(pBuffer_, temp, width, height);
    if (error) {
        cout << "encode error" << error << ": " << lodepng_error_text(error) << endl;
    } else {
        width_ = width;
        height_ = height;
    }
}

void Image::convert(LodePNGColorType type) {

}
