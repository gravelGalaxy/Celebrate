#include "ascii_image_generator.h"
#include "lodepng.h"
using namespace std;

void AImageGenerator::set_ascii_chars(const std::string &chars)
{
    if (chars.length() < least_chars_num_) {
        throw ACharsNumsNotSatisfyException("the num of the ascii characters is too small.");
    }
    ascii_chars_ = chars;
}

void AImageGenerator::generate(const std::string &input_path, const std::string &output_path) {


}

void AImageGenerator::generate(const Image &image, const string &output_path) {
    pair<unsigned, unsigned> size = image.size();
    unsigned width = target_width_;
    unsigned height = size.second / size.first * width * ratio_;
    vector<unsigned char> resized_img;
    vector<unsigned char> resource_img = image.
    unsigned error = lodepng::encode(resized_img, image, width, height, LCT_GREY, 8);


}
