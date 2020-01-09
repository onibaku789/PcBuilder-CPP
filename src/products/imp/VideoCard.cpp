//
// Created by Narancs on 2020. 01. 06..
//

#include "VideoCard.h"

VideoCard::VideoCard() {
    std::cout << "VideoCard NoArgs" << std::endl;
}

VideoCard::~VideoCard() {
    std::cout << "Destroying VideoCard" << std::endl;
}

int VideoCard::getCurrentPrice() const {
    int ageInDays = getAge();
    return ageInDays < 30 ? initPrice : (int) initPrice * (ageInDays >= 30 && ageInDays < 90 ? 0.9 : 0.8);
}

std::string VideoCard::getType() const {
    return "VGA";
}

char VideoCard::getCharCode() const {
    return ProductTypes::Video;
}

void VideoCard::printParams(std::ostream &ostream) const {
    Product::printParams(ostream);
    ostream << ", " << "VideoMemory: " << memory << ", " << "Hz: " << hz;
}

void VideoCard::loadParamsFromStream(std::istream &istream) {
    Product::loadParamsFromStream(istream);
    istream >> memory >> hz;
}

void VideoCard::writeParamsToStream(std::ostream &ostream) const {
    Product::writeParamsToStream(ostream);
    ostream << ' ' << memory << ' ' << hz;
}

VideoCard::VideoCard(int initPrice, time_t dateOfAcq, const std::string &name, int memory, int hz) :
        Product(initPrice, dateOfAcq, name), memory(memory), hz(hz) {
    std::cout << "VideoCard AllArgs" << std::endl;
}

bool VideoCard::operator==(const VideoCard &rhs) const {
    return static_cast<const Product &>(*this) == static_cast<const Product &>(rhs) &&
           memory == rhs.memory &&
           hz == rhs.hz;
}

bool VideoCard::operator!=(const VideoCard &rhs) const {
    return !(rhs == *this);
}

VideoCard::VideoCard(const VideoCard &other) noexcept : Product(other) {
    std::cout << "VideoCard Ctor" << std::endl;
    memory = other.memory;
    hz = other.hz;
}

VideoCard &VideoCard::operator=(const VideoCard &other) noexcept {
    std::cout << "VideoCard copy assign" << std::endl;
    Product::operator=(other);
    memory = other.memory;
    hz = other.hz;
    return *this;
}

VideoCard::VideoCard(VideoCard &&other) noexcept : Product(std::forward<Product>(other)) {
    std::cout << "VideoCard movetor" << std::endl;
    memory = other.memory;
    hz = other.hz;
    other.memory = 0;
    other.hz = 0;
}

VideoCard &VideoCard::operator=(VideoCard &&other) noexcept {
    std::cout << "VideoCard move assign" << std::endl;
    Product::operator=(std::forward<Product>(other));
    memory = other.memory;
    hz = other.hz;

    other.memory = 0;
    other.hz = 0;
    return *this;
}




