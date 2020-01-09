
#include <fstream>
#include <cassert>
#include <c++/4.8.3/stdexcept>
#include "products/factory/ProductFactory.h"
#include "products/factory/imp/ComputerProductFactory.h"
#include "products/ProductInventory.h"

#include "products/imp/HardDisk.h"
#include "products/imp/Display.h"
#include "products/imp/VideoCard.h"

void readInvFromFile(ProductInventory &inventory,
                     const std::string &fileName = "C:\\Users\\Narancs\\CLionProjects\\pcbuilder\\default_IN.txt");


void writeInvToFile(ProductInventory &inventory,
                    const std::string &fileName = "C:\\Users\\Narancs\\CLionProjects\\pcbuilder\\default_OUT.txt");

template<typename T>
T copyProduct(T &product);

template<typename T>
T moveProduct(T product);

void readInvFromCode(time_t time1);

void readInvFromFileTest();

void copyTest(time_t time1);

void moveTest(time_t time1);

int main() {
    try {
        ProductFactory::setProductFactory(new ComputerProductFactory());
        tm tm;
        tm.tm_year = (2018 - 1900);
        tm.tm_mon = (5 - 1);
        tm.tm_mday = (10 + 1);
        tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
        tm.tm_isdst = -1;
        time_t twokeighteen = mktime(&tm);

        time_t currentTime;
        time(&currentTime);


        //ProductInventory from code;
      //  readInvFromCode(twokeighteen);


        //ProductInventory from file;
        //readInvFromFileTest();

        //copytor and copyassign
      // copyTest(currentTime);

        //movetor and moveassign
        //moveTest(currentTime);
    }
    catch (const std::invalid_argument &exception) {
        std::cerr << "There was an error(invalid_argument): " << std::endl;
        std::cerr << exception.what() << std::endl;
    } catch (const std::out_of_range &exception) {
        std::cerr << "There was an error(out_of_range): " << std::endl;
        std::cerr << exception.what() << std::endl;
    } catch (...) {
        std::cerr << "Unexpected error occured." << std::endl;
    }
    return 0;
}

void readInvFromFile(ProductInventory &inventory, const std::string &fileName) {
    std::ifstream infile(fileName);
    if (!infile) {
        throw std::invalid_argument("Error opening input file");

    }
    inventory.readInventory(infile);
    std::cout << "Reading input file" << std::endl;
}

void writeInvToFile(ProductInventory &inventory, const std::string &fileName) {
    std::ofstream outfile(fileName);
    if (!outfile) {
        throw std::invalid_argument("Error opening output file");
    }
    inventory.writeInventory(outfile);
    std::cout << "Writing output file" << std::endl;
}

void readInvFromCode(time_t time1) {
    ProductInventory inv1;
    inv1.addProduct(new Display(35641, time1, "Samsung S24D330H Monitor", 22, 12));
    inv1.addProduct(
            new HardDisk(11700, time1, "Western Digital Caviar Blue 3.5 1TB 7200rpm 64MB SATA3 WD10EZEX", 7200));
    inv1.addProduct(new VideoCard(94000, time1, "GIGABYTE GeForce GTX 1660 Ti OC 6GB (GV-N166TOC-6GD) ", 6, 1800));
    inv1.printProducts(std::cout);
}

void readInvFromFileTest() {
    ProductInventory inventory2;
    readInvFromFile(inventory2);
    inventory2.printProducts(std::cout);
    writeInvToFile(inventory2);
}

void copyTest(time_t time1) {
    auto hdd =  HardDisk(11700, time1, "Western Digital Caviar Blue 3.5 1TB 7200rpm 64MB SATA3 WD10EZEX",
                         7200);
    auto vga =  VideoCard(94000, time1, "GIGABYTE GeForce GTX 1660 Ti OC 6GB (GV-N166TOC-6GD) ", 6, 1800);

    auto vga1 = copyProduct<VideoCard>(vga);
    VideoCard vga2;
    vga2 = vga1;
}

void moveTest(time_t time1) {

    std::vector<HardDisk> hdds;
    hdds.emplace_back(11700, time1, "Western Digital  Blue 3.5 1TB 7200rpm 64MB SATA3 ",
                      7200);
    hdds.emplace_back(117020, time1, "Western Digital  Green 4 2TB  128MB SATA3 ",
                      12000);

    hdds.insert(hdds.begin() + 1, HardDisk(1123, time1, "Western Digital  Green 123 222TB  128MB SATA3 ",
                                           12000));
    HardDisk hdd;
    hdd = moveProduct<HardDisk>(HardDisk(1123, time1, "Western Digital  Green 123 222TB  128MB SATA3 ",
                                         12000));
}

template<typename T>
T moveProduct(T product) {
    std::cout << "MoveProduct called" << std::endl;
    return product;
}

template<typename T>
T copyProduct(T &product) {
    std::cout << "CopyProduct called" << std::endl;
    return product;
}
