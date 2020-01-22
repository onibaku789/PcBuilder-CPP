//
// Created by Narancs on 2020. 01. 05..
//

#include <stdexcept>
#include "ProductFactory.h"


Product *ProductFactory::readAndCreateProduct(std::istream &istream) {
    if (istream.fail() || istream.eof())
       throw std::invalid_argument("ProductFactory::readAndCreateProduct - Line must start with a character.");
    char typeCode = '0';
    istream >> typeCode;

    if (istream.fail() || istream.eof()) {
        throw std::invalid_argument("ProductFactory::readAndCreateProduct - Wrong file format.");
    }

    Product *product = createProduct(typeCode);
    if (!product) {
        throw std::invalid_argument("ProductFactory::readAndCreateProduct - The product could not be created.");
    }
    return product;
}

ProductFactory::~ProductFactory() {
    std::cout << "\n\n\n\nDestroying ProductFactory\n\n\n\n" << instance << std::endl;
    delete ProductFactory::instance;
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

