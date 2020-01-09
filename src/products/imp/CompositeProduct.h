//
// Created by Narancs on 2020. 01. 05..
//

#ifndef PCBUILDER_COMPOSITEPRODUCT_H
#define PCBUILDER_COMPOSITEPRODUCT_H

#include <vector>
#include <iostream>
#include "../Product.h"

class CompositeProduct : public Product {
protected:
    void printParams(std::ostream &ostream) const override;

    void loadParamsFromStream(std::istream &istream) override;

    void writeParamsToStream(std::ostream &ostream) const override;

private:
    std::vector<Product *> parts;

public:
    CompositeProduct();

    CompositeProduct(const CompositeProduct &other) noexcept;

    CompositeProduct &operator=(const CompositeProduct &other) noexcept;

    CompositeProduct(CompositeProduct &&other) noexcept;

    CompositeProduct &operator=(CompositeProduct &&other) noexcept;

    ~CompositeProduct() override;

    void addPart(Product *product);

    int getCurrentPrice() const override;

    std::string getType() const override;

    char getCharCode() const override;

    bool operator==(const CompositeProduct &rhs) const;

    bool operator!=(const CompositeProduct &rhs) const;

};


#endif //PCBUILDER_COMPOSITEPRODUCT_H
