//
// Created by Narancs on 2020. 01. 05..
//

#include "ProductFactory.h"

Product * ProductFactory::readAndCreateProduct(std::istream &istream) {
    if (!istream.good())
        return nullptr;
    char typeCode;
    istream >> typeCode;

    if(!istream.good()){
        if( istream.eof()) return nullptr;

        //TODO Throw Exception
        return nullptr;
    }

    Product * product = CreateProduct(typeCode);
    if (product == nullptr){
        //TODO throw exception
    }
    return  product;
}

ProductFactory::~ProductFactory() {

}
ProductFactory* ProductFactory::instance = nullptr;

void ProductFactory::setProductFactory(ProductFactory *pf) {
    instance = pf;
}

 ProductFactory *ProductFactory::getInstance() {
    if(!instance){
        instance = new ProductFactory();
    }
    return instance;
}

Product *ProductFactory::CreateProduct(char typeCode) const {
    return nullptr;
}

