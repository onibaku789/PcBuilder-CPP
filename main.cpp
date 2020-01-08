
#include <fstream>
#include <cassert>
#include <c++/4.8.3/stdexcept>
#include "src/products/factory/ProductFactory.h"
#include "src/products/factory/imp/ComputerProductFactory.h"
#include "src/products/ProductInventory.h"

#include "src/products/imp/HardDisk.h"
#include "src/products/imp/Display.h"

void readInvFromFile(ProductInventory &inventory, const std::string& fileName ="C:\\Users\\Narancs\\CLionProjects\\pcbuilder\\default_IN.txt");


void writeInvToFile(ProductInventory &inventory, const std::string& fileName = "C:\\Users\\Narancs\\CLionProjects\\pcbuilder\\default_OUT.txt");

int main() {
    try {
        ProductFactory::init(new ComputerProductFactory());

        time_t currentTime;
        time(&currentTime);
        ProductInventory inv1;
        inv1.addProduct(new Display(1, currentTime, "DISPLAYXD", 13, 12));
        inv1.addProduct(new HardDisk(2500, currentTime, "asd", 5000));
        inv1.addProduct(new HardDisk(300, currentTime, "dikk", 4000));
        inv1.printProducts(std::cout);



        ProductInventory inventory2;
        readInvFromFile(inventory2);
        inventory2.printProducts(std::cout);

        writeInvToFile(inventory2);

        auto *product = new HardDisk(2500,currentTime,"copy",5000);
        product->print(std::cout);

        auto *product1 = new HardDisk(330302320,currentTime,"copy1",500);

        product1->print(std::cout);

        //Copy Assign
       *product1 = *product;

       product1->print(std::cout);

       //Movetor
        HardDisk product2 = std::move(*product1);


        //Move Assign
        *product = std::move(product2);



    }
    catch (const std::exception &exception) {
        std::cerr << "There was an error: " << std::endl;
        std::cerr << exception.what() << std::endl;
    } catch (...) {
        std::cerr << "Unexpected error occured." << std::endl;
    }

    return 0;
}

void readInvFromFile(ProductInventory &inventory, const std::string& fileName) {
    std::ifstream infile(fileName);
    if (!infile) {
        throw std::invalid_argument("Error opening input file");

    }
    inventory.readInventory(infile);
    std::cout << "Reading input file" << std::endl;
}

void writeInvToFile(ProductInventory &inventory, const std::string& fileName) {
    std::ofstream outfile(fileName);
    if (!outfile) {
        throw std::invalid_argument("Error opening output file");
    }
    inventory.writeInventory(outfile);
    std::cout << "Writing output file" << std::endl;
}
