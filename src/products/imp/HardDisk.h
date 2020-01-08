//
// Created by Narancs on 2020. 01. 05..
//

#ifndef PCBUILDER_HARDDISK_H
#define PCBUILDER_HARDDISK_H


#include "../Product.h"

class HardDisk : public Product{
    int speedRPM;
public:
    HardDisk();

    HardDisk(int initPrice, time_t dateOfAcq, const std::string &name, int speedRpm);

    HardDisk(const HardDisk &other)noexcept;

    HardDisk &operator=(const HardDisk &other)noexcept;

    HardDisk(HardDisk &&other) noexcept;

    HardDisk &operator=(HardDisk &&other)noexcept;

    int getCurrentPrice() const override;

    std::string getType() const override;

    char getCharCode() const override;

     ~HardDisk() override;

    bool operator==(const HardDisk &rhs) const;

    bool operator!=(const HardDisk &rhs) const;

protected:
    void printParams(std::ostream &ostream) const override;

    void loadParamsFromStream(std::istream &istream) override;

    void writeParamsToStream(std::ostream &ostream) const override;




};


#endif //PCBUILDER_HARDDISK_H
