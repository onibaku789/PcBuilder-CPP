//
// Created by Narancs on 2020. 01. 05..
//

#ifndef PCBUILDER_COMPUTERPRODUCTFACTORY_H
#define PCBUILDER_COMPUTERPRODUCTFACTORY_H


#include "../ProductFactory.h"

class ComputerProductFactory : public ProductFactory{
public:
    Product * CreateProduct(char typeCode) const override ;
};


#endif //PCBUILDER_COMPUTERPRODUCTFACTORY_H
