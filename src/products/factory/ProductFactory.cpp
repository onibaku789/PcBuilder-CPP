//
// Created by Narancs on 2020. 01. 05..
//

#include "ProductFactory.h"

Product *ProductFactory::readAndCreateProduct(std::istream &istream) {
    if (istream.bad())
       throw std::invalid_argument("Line must start with a character.");
    char typeCode;
    istream >> typeCode;

    if (istream.bad() || istream.eof()) {
        throw std::invalid_argument("Wrong file format.");
    }

    Product *product = createProduct(typeCode);
    if (!product) {
        throw std::invalid_argument("The product could not be created.");
    }
    return product;
}

ProductFactory::~ProductFactory() {
}

ProductFactory *ProductFactory::instance = nullptr;

void ProductFactory::setProductFactory(ProductFactory *pf) {
    instance = pf;
}

ProductFactory *ProductFactory::getInstance() {
    if (!instance) {
        instance = new ProductFactory();
    }
    return instance;
}

Product *ProductFactory::createProduct(char typeCode) const {
    return nullptr;
}

