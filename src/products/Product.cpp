//
// Created by Narancs on 2020. 01. 05..
//

#include "Product.h"

#include <utility>
#include <stdexcept>
#include <cstring>
#include <sstream>

Product::Product() {
    //std::cout << "Product NoArgs" << std::endl;
}

Product::Product(int initPrice, time_t dateOfAcq, std::string name) :
        initPrice(initPrice), dateOfAcq(dateOfAcq), name(std::move(name)) {
    //std::cout << "Product AllArgs" <<std::endl;
}

int Product::getInitPrice() const {
    return initPrice;
}

time_t Product::getDateOfAcq() const {
    return dateOfAcq;
}

const std::string &Product::getName() const {
    return name;
}

int Product::getAge() const {
    time_t currentTime;
    time(&currentTime);
    double diffinsec = difftime(currentTime, dateOfAcq);
    if (diffinsec < 0) throw std::invalid_argument("Age cannot be negative.");
    return (int) diffinsec / (3600 * 24);
}

double Product::getCurrentPrice() const {
    return initPrice;
}

void Product::print(std::ostream &ostream) const {
    ostream << "Type: " << getType() << ", ";
    ostream << "Name: " << getName();
    printParams(ostream);
}

void Product::printParams(std::ostream &ostream) const {
    char strDateOAcq[9];
    int age = getAge();
    strftime(strDateOAcq, 9, "%Y%m%d", gmtime(&dateOfAcq));
    ostream << ", " << "InitalPrice: " << initPrice << " Ft."
            << ", " << "DateOfAcquisiton: " << strDateOAcq
            << ", " << "Age: " << age << (age > 1 ? " days" : " day")
            << ", " << "Current price: " << getCurrentPrice() << " Ft.";
}

void Product::writeParamsToStream(std::ostream &ostream) const {
    char strDateOfAcq[9];
    tm *t = localtime(&dateOfAcq);
    strftime(strDateOfAcq, 9, "%Y%m%d", t);
    ostream << ' ' << name << ' ' << initPrice << ' ' << strDateOfAcq;
}

void Product::loadParamsFromStream(std::istream &istream) {
    if (istream.fail() || istream.eof()) {
        throw std::invalid_argument("Product::loadParamsFromStream - Invalid stream");
    }
    istream >> name;
    istream >> initPrice;
    std::string buff;
    istream.width(9);
    istream >> buff;
    if (buff.size() != 8)
        throw std::range_error("Invalid time format.");
    tm tm{};
    int year, month, day;
    std::istringstream iss(buff.substr(0, 4));
    iss >> year;
    if (year < 0)
        throw std::invalid_argument("Year cannot be negative");
    std::istringstream iss2(buff.substr(4, 2));
    iss2 >> month;
    if (month > 12 && month < 0)
        throw std::invalid_argument("Wrong month format.");
    std::istringstream iss3(buff.substr(6, 2));
    iss3 >> day;
    if (day < 0 && day > 31)
        throw std::invalid_argument("Wrong day format");

    tm.tm_year = (year - 1900);
    tm.tm_mon = (month - 1);
    tm.tm_mday = (day + 1);
    tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
    tm.tm_isdst = -1;

    dateOfAcq = mktime(&tm);
}

std::ostream &operator<<(std::ostream &ostream, const Product &product) {
    ostream << product.getCharCode();
    product.writeParamsToStream(ostream);
    return ostream;
}

std::istream &operator>>(std::istream &istream, Product &product) {
    product.loadParamsFromStream(istream);
    return istream;
}

Product::~Product() {
    // std::cout << "Destroying Product" << std::endl;
}

bool Product::operator==(const Product &rhs) const {
    return initPrice == rhs.initPrice &&
           dateOfAcq == rhs.dateOfAcq &&
           name == rhs.name;
}

bool Product::operator!=(const Product &rhs) const {
    return !(rhs == *this);
}








