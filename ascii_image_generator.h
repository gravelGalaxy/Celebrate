#pragma
#include <string>
#include <stdexcept>
#include <type_traits>
#include <memory>
#include "image.h"

class AImageGenerator
{
public:
    AImageGenerator() = default;
    AImageGenerator(unsigned target_height, unsigned target_width): target_height_(target_height), target_width_(target_width){}
    ~AImageGenerator() = default;
    void set_ascii_chars(const std::string &chars);
    void generate(const std::string& input_path, const std::string& output_path);
    void generate(const Image& image, const std::string& output_path);
private:
    std::string ascii_chars_ = "$@B%8&WM#*oahkbdpqmZOLJUYXzcunxrft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    // 设置ascii_chars的基本数量要求
    uint64_t least_chars_num_ = 64;
    double ratio_ = 0.45;
    unsigned target_height_ = 100;
    unsigned target_width_ = 100;
};

class ACharsNumsNotSatisfyException : public std::exception
{
public:
    explicit ACharsNumsNotSatisfyException(const char *msg) : message(msg) {}
    virtual const char *what() { return message.what(); }
    ~ACharsNumsNotSatisfyException() noexcept override = default;

private:
    std::runtime_error message;
};