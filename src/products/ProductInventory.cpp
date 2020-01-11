//
// Created by Narancs on 2020. 01. 06..
//


#include <stdexcept>
#include <vector>
#include <numeric>
#include <string>

#include "ProductInventory.h"
#include "factory/ProductFactory.h"


ProductInventory::~ProductInventory() {
    std::cout << "Destroying ProductInventory" << std::endl;
    for (auto &item:products) {
        delete item;
    }
    products.clear();
}

void ProductInventory::readInventory(std::istream &istream) {
    istream >> std::skipws;
    while (istream.good()) {
        Product *product = ProductFactory::getInstance()->readAndCreateProduct(istream);
        if (product) {
            istream >> *product;
            addProduct(product);
        } else {
            throw std::invalid_argument("ProductInventory::readInventory - The product could not be created.");
        }
    }
}

void ProductInventory::writeInventory(std::ostream &ostream) const {
    for (auto &item:products) {
        item->print(ostream);
        ostream << std::endl;
    }
}

void ProductInventory::printProducts(std::ostream &ostream) const {
    std::cout << "Printing product inventory" << std::endl
              << "---------------------------------------------" << std::endl
              << "Price of all products: " << getProductsPrice() << " Ft." << std::endl;

    for (auto &item:products) {
        item->print(ostream);
        ostream << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl
              << "Done printing product inventory" << std::endl;

}

void ProductInventory::addProduct(Product *product) {
    if (!product) {
        throw std::invalid_argument("ProductInventory::addProduct - The product parameter can not null.");
    }
    products.push_back(product);
}

int ProductInventory::getProductsPrice() const {
    return std::accumulate(products.begin(), products.end(), 0, [](int current_sum, const Product *product) {
        return current_sum + product->getCurrentPrice();
    });
}

ProductInventory::ProductInventory() {
    std::cout << "ProductInventory NoArgs" << std::endl;
}


