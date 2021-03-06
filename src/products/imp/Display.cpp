//
// Created by Narancs on 2020. 01. 06..
//

#include "Display.h"

Display::Display() {
    std::cout << "Display NoArgs" << std::endl;
}

Display::Display(int initPrice, time_t dateOfAcq, const std::string &name, int inchHeight, int inchWidth) : Product(
        initPrice, dateOfAcq, name), inchHeight(inchHeight), inchWidth(inchWidth) {
    std::cout << "Display AllArgs" << std::endl;
}


Display::~Display() {
    std::cout << "Destroying Display" << std::endl;

}

double Display::getCurrentPrice() const {
    int ageInDays = getAge();
    return ageInDays < 30 ? initPrice : initPrice * (ageInDays >= 30 && ageInDays < 90 ? 0.9 : 0.8);
}

std::string Display::getType() const {
    return "Display";
}

char Display::getCharCode() const {
    return ProductTypes::Screen;
}

void Display::printParams(std::ostream &ostream) const {
    Product::printParams(ostream);
    ostream << ", " << "Inch Height: " << inchHeight << " inch";
    ostream << ", " << "Inch Width: " << inchWidth << " inch";
}

void Display::loadParamsFromStream(std::istream &istream) {
    Product::loadParamsFromStream(istream);
    istream >> inchHeight >> inchWidth;
}

void Display::writeParamsToStream(std::ostream &ostream) const {
    Product::writeParamsToStream(ostream);
    ostream << ' ' << inchHeight << ' ' << inchWidth;
}


bool Display::operator==(const Display &rhs) const {
    return static_cast<const Product &>(*this) == static_cast<const Product &>(rhs) &&
           inchHeight == rhs.inchHeight &&
           inchWidth == rhs.inchWidth;
}

bool Display::operator!=(const Display &rhs) const {
    return !(rhs == *this);
}

Display::Display(const Display &other) noexcept : Product(other) {
    std::cout << "Display Ctor" << std::endl;
    inchHeight = other.inchHeight;
    inchWidth = other.inchHeight;
}

Display &Display::operator=(const Display &other) noexcept {
    std::cout << "Display copy assign" << std::endl;
    Product::operator=(other);
    if (this != &other) {
        inchHeight = other.inchHeight;
        inchWidth = other.inchHeight;
    }
    return *this;
}

Display::Display(Display &&other) noexcept : Product(std::forward<Product>(other)) {
    std::cout << "Display movetor" << std::endl;
    inchHeight = other.inchHeight;
    inchWidth = other.inchHeight;
    other.inchHeight = 0;
    other.inchWidth = 0;

}

Display &Display::operator=(Display &&other) noexcept {
    std::cout << "Display move assign" << std::endl;
    Product::operator=(std::forward<Product>(other));
    if (this != &other) {
        inchHeight = other.inchHeight;
        inchWidth = other.inchHeight;
        other.inchHeight = 0;
        other.inchWidth = 0;
    }
    return *this;
}



