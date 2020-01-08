//
// Created by Narancs on 2020. 01. 06..
//

#include "Display.h"

Display::Display() {
    std::cout << "Display NoArgs" << std::endl;
};

Display::Display(int initPrice, time_t dateOfAcq, const std::string &name, int inchHeight, int inchWidth) : Product(
        initPrice, dateOfAcq, name), inchHeight(inchHeight), inchWidth(inchWidth) {
    std::cout << "Display AllArgs" << std::endl;
}


Display::~Display() {
    std::cout << "Destroying Display" << std::endl;

}

int Display::getCurrentPrice() const {
    int ageInDays = getAge();
    return ageInDays < 30 ? initPrice : (int) initPrice * (ageInDays >= 30 && ageInDays < 90 ? 0.9 : 0.8);
}

std::string Display::getType() const {
    return "Display";
}

char Display::getCharCode() const {
    return ProductTypes::Screen;
}

void Display::printParams(std::ostream &ostream) const {
    Product::printParams(ostream);
   ostream << ", " << "Inch Height: " << inchHeight;
    ostream << ", " << "Inch Width: " << inchWidth;
}

void Display::loadParamsFromStream(std::istream &istream) {
    Product::loadParamsFromStream(istream);
   istream >> inchHeight;
   istream >> inchWidth;
}

void Display::writeParamsToStream(std::ostream &ostream) const {
    Product::writeParamsToStream(ostream);
   ostream <<' ' << inchWidth << ' ' << inchHeight;
}


bool Display::operator==(const Display &rhs) const {
    return static_cast<const Product &>(*this) == static_cast<const Product &>(rhs) &&
           inchHeight == rhs.inchHeight &&
           inchWidth == rhs.inchWidth;
}

bool Display::operator!=(const Display &rhs) const {
    return !(rhs == *this);
}


