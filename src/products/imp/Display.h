//
// Created by Narancs on 2020. 01. 06..
//

#ifndef PCBUILDER_DISPLAY_H
#define PCBUILDER_DISPLAY_H


#include "../Product.h"

class Display : public Product{
    int inchHeight;
   int inchWidth;
public:
    Display();

    Display(int initPrice, time_t dateOfAcq, const std::string &name, int inchHeight, int inchWidth);

    ~Display() override;

    int getCurrentPrice() const override;

    std::string getType() const override;

    char getCharCode() const override;

    bool operator==(const Display &rhs) const;

    bool operator!=(const Display &rhs) const;

protected:
    void printParams(std::ostream &ostream) const override;

    void loadParamsFromStream(std::istream &istream) override;

    void writeParamsToStream(std::ostream &ostream) const override;


};


#endif //PCBUILDER_DISPLAY_H
