//
// Created by Narancs on 2020. 01. 05..
//

#include <numeric>
#include "CompositeProduct.h"
#include "../factory/ProductFactory.h"

void CompositeProduct::printParams(std::ostream &ostream) const {
    Product::printParams(ostream);
    ostream << std::endl << " Items: ";
    for (unsigned int i = 0; i < parts.size(); ++i) {
        ostream << std::endl << " " << i + 1 << ".: ";
        parts[i]->print(ostream);
    }
}

void CompositeProduct::loadParamsFromStream(std::istream &istream) {
    Product::loadParamsFromStream(istream);
    int itemCount;
    istream >> itemCount;

    for (int i = 0; i < itemCount; ++i) {
        Product *product = ProductFactory::getInstance()->readAndCreateProduct(istream);
        if (product) {
            istream >> *product;
            addPart(product);
        }
    }
}

void CompositeProduct::writeParamsToStream(std::ostream &ostream) const {
    Product::writeParamsToStream(ostream);
    ostream << ' ' << parts.size();
    for (auto &i:parts) {
        ostream << std::endl << *i;
    }
}

CompositeProduct::CompositeProduct() {
    std::cout << "CompositeProduct NoArgs" << std::endl;
}

CompositeProduct::~CompositeProduct() {
    std::cout << "Destroying CompositeProduct" << std::endl;
    for (auto &item: parts) {
        std::cout << "Destroying Product: " << item->getType() << std::endl;
        delete item;
    }
}

void CompositeProduct::addPart(Product *product) {
    parts.push_back(product);

}

double CompositeProduct::getCurrentPrice() const {
    return std::accumulate(parts.begin(), parts.end(), 0, [](int current_sum, const Product *product) {
        return current_sum + product->getCurrentPrice();
    });
}

std::string CompositeProduct::getType() const {
    return "CompositeProduct";
}

char CompositeProduct::getCharCode() const {
    return ProductTypes::Composite;
}

bool CompositeProduct::operator==(const CompositeProduct &rhs) const {
    return static_cast<const Product &>(*this) == static_cast<const Product &>(rhs) &&
           parts == rhs.parts;
}

bool CompositeProduct::operator!=(const CompositeProduct &rhs) const {
    return !(rhs == *this);
}

CompositeProduct::CompositeProduct(const CompositeProduct &other) noexcept: Product(other) {
    std::cout << "CompositeProduct ctor" << std::endl;
    parts = other.parts;
}

CompositeProduct &CompositeProduct::operator=(const CompositeProduct &other) noexcept {
    std::cout << "CompositeProduct assign copy" << std::endl;
    Product::operator=(other);
    parts = other.parts;
    return *this;
}

CompositeProduct::CompositeProduct(CompositeProduct &&other) noexcept: Product(std::forward<Product>(other)) {
    std::cout << "CompositeProduct movetor" << std::endl;
    parts = other.parts;
    other.parts.clear();
}

CompositeProduct &CompositeProduct::operator=(CompositeProduct &&other) noexcept {
    std::cout << "CompositeProduct assign move" << std::endl;
    Product::operator=(std::forward<Product>(other));
    parts = other.parts;
    return *this;
}



