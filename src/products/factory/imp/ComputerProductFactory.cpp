//
// Created by Narancs on 2020. 01. 05..
//

#include "ComputerProductFactory.h"
#include "../../imp/HardDisk.h"
#include "../../imp/Display.h"
#include "../../imp/CompositeProduct.h"
#include "../../imp/VideoCard.h"

Product *ComputerProductFactory::CreateProduct(char typeCode) const {
    switch (typeCode) {
        case ProductTypes::HardDrive:
            return new HardDisk();
        case ProductTypes::Screen:
            return new Display();
        case ProductTypes::Composite:
            return new CompositeProduct();
        case ProductTypes::Video:
            return new VideoCard();
        default:
            return nullptr;
    }

}
