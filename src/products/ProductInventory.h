//
// Created by Narancs on 2020. 01. 06..
//

#ifndef PCBUILDER_PRODUCTINVENTORY_H
#define PCBUILDER_PRODUCTINVENTORY_H

#include <vector>
#include "Product.h"

class ProductInventory {


public:

    ProductInventory();
    virtual ~ProductInventory();
    void readInventory(std::istream& istream);
    void writeInventory(std::ostream& ostream)const;
    void printProducts(std::ostream& ostream)const;
    void addProduct(Product* product);
    int getProductsPrice() const;

protected:
    std::vector<Product*> products;
};


#endif //PCBUILDER_PRODUCTINVENTORY_H
