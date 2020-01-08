//
// Created by Narancs on 2020. 01. 05..
//

#ifndef PCBUILDER_PRODUCTFACTORY_H
#define PCBUILDER_PRODUCTFACTORY_H


#include "../Product.h"

class ProductFactory {
    static ProductFactory * instance;

public:
    virtual ~ProductFactory();
    static ProductFactory * getInstance();
    static void init(ProductFactory * pf);

    Product * readAndCreateProduct(std::istream& istream);
    virtual Product * CreateProduct(char typeCode) const ;


};


#endif //PCBUILDER_PRODUCTFACTORY_H
