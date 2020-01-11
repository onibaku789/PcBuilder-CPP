//
// Created by Narancs on 2020. 01. 05..
//

#include "HardDisk.h"

int HardDisk::getCurrentPrice() const {
    int ageInDays = getAge();
    return ageInDays < 30 ? initPrice : (int) initPrice * (ageInDays >= 30 && ageInDays < 90 ? 0.9 : 0.8);
}

HardDisk::~HardDisk() {
    std::cout << "Destroying HardDisk" << std::endl;

}

void HardDisk::printParams(std::ostream &ostream) const {
    Product::printParams(ostream);
    ostream << ", " << "SpeedRMP: " << speedRPM << " RPM";
}

void HardDisk::loadParamsFromStream(std::istream &istream) {
    Product::loadParamsFromStream(istream);
    istream >> speedRPM;
}

void HardDisk::writeParamsToStream(std::ostream &ostream) const {
    Product::writeParamsToStream(ostream);
    ostream << ' ' << speedRPM;
}

std::string HardDisk::getType() const { return "HardDisk"; }

char HardDisk::getCharCode() const { return ProductTypes::HardDrive; }


bool HardDisk::operator==(const HardDisk &rhs) const {
    return static_cast<const Product &>(*this) == static_cast<const Product &>(rhs) &&
           speedRPM == rhs.speedRPM;
}

bool HardDisk::operator!=(const HardDisk &rhs) const {
    return !(rhs == *this);
}

HardDisk::HardDisk(const HardDisk &other) noexcept : Product(other) {
    std::cout << "HardDisk ctor" << std::endl;
    speedRPM = other.speedRPM;

}

HardDisk &HardDisk::operator=(const HardDisk &other) noexcept {
    std::cout << "HardDisk copy assign" << std::endl;
    Product::operator=(other);
    speedRPM = other.speedRPM;
    return *this;
}

HardDisk::HardDisk(HardDisk &&other) noexcept : Product(std::forward<Product>(other)) {
    std::cout << "HardDisk movetor" << std::endl;
    speedRPM = other.speedRPM;
}

HardDisk &HardDisk::operator=(HardDisk &&other) noexcept {
    std::cout << "HardDisk move assign" << std::endl;
    Product::operator=(std::forward<Product>(other));
    speedRPM = other.speedRPM;
    return *this;
}


HardDisk::HardDisk() {
    std::cout << "HardDisk NoArgs" << std::endl;
}

HardDisk::HardDisk(int initPrice, time_t dateOfAcq, const std::string &name, int speedRpm)
        : Product(initPrice, dateOfAcq, name), speedRPM(speedRpm) {
    std::cout << "HardDisk AllArgs" << std::endl;
}