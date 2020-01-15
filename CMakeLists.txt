cmake_minimum_required(VERSION 3.15)
project(pcbuilder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_executable(pcbuilder src/main.cpp src/products/Product.cpp src/products/Product.h src/products/imp/HardDisk.cpp src/products/imp/HardDisk.h src/products/imp/CompositeProduct.cpp src/products/imp/CompositeProduct.h src/products/factory/ProductFactory.cpp src/products/factory/ProductFactory.h src/products/factory/imp/ComputerProductFactory.cpp src/products/factory/imp/ComputerProductFactory.h src/products/ProductInventory.cpp src/products/ProductInventory.h src/products/imp/Display.cpp src/products/imp/Display.h src/products/imp/VideoCard.cpp src/products/imp/VideoCard.h)