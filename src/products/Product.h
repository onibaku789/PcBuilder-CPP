//
// Created by Narancs on 2020. 01. 05..
//

#ifndef PCBUILDER_PRODUCT_H
#define PCBUILDER_PRODUCT_H


#include <ctime>
#include <string>
#include <iostream>

class Product {
protected:
    int initPrice;
    time_t dateOfAcq;
    std::string name;

    virtual void printParams(std::ostream &ostream) const;

    virtual void loadParamsFromStream(std::istream &istream);

    virtual void writeParamsToStream(std::ostream &ostream) const;

public:
    Product();

    Product(int initPrice, time_t dateOfAcq, std::string name);

    virtual ~Product();

    int getInitPrice() const;

    time_t getDateOfAcq() const;

    const std::string &getName() const;

    int getAge() const;

    virtual double getCurrentPrice() const;

    void print(std::ostream &ostream) const;

    virtual std::string getType() const { return ""; };

    virtual char getCharCode() const { return '0'; };

    friend std::istream &operator>>(std::istream &istream, Product &product);

    friend std::ostream &operator<<(std::ostream &ostream, const Product &product);

    bool operator==(const Product &rhs) const;

    bool operator!=(const Product &rhs) const;

    Product(const Product &other) : initPrice(other.initPrice), dateOfAcq(other.dateOfAcq), name(other.name) {
        std::cout << "Product Ctor" << std::endl;
    }

     Product &operator=(const Product &other) noexcept {
         std::cout << "Product copy assign" << std::endl;
         if (this != &other) {
             initPrice = other.initPrice;
             dateOfAcq = other.dateOfAcq;
             name = other.name;
         }
         return *this;
     }

    Product(Product &&other) noexcept: initPrice(0), dateOfAcq(0), name("") {
        std::cout << "Product movetor" << std::endl;
        initPrice = other.initPrice;
        dateOfAcq = other.dateOfAcq;
        name = other.name;

        other.initPrice = 0;
        other.dateOfAcq = 0;
        other.name = "";
    }

    Product &operator=(Product &&other) noexcept {
        std::cout << "Product move assign" << std::endl;
        if (this != &other) {
            initPrice = other.initPrice;
            dateOfAcq = other.dateOfAcq;
            name = other.name;

            other.initPrice = 0;
            other.dateOfAcq = 0;
            other.name = "";
        }
        return *this;
    }
};

enum ProductTypes {
    HardDrive = 'h',
    Screen = 's',
    Composite = 'c',
    Video = 'v'
};

#endif //PCBUILDER_PRODUCT_H
