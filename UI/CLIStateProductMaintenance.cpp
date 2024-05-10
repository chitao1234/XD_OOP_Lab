//
// Created by chi on 24/05/01.
//

#include <iostream>
#include "CLIStateProductMaintenance.h"
#include "Service/StorageService.h"

CLIStateProductMaintenance::CLIStateProductMaintenance(CLIUserInterface &userInterface) :
        userInterface(userInterface),
        productDisplay(StorageService::getInstance()->getProductRepository().listProducts()) {
}

void CLIStateProductMaintenance::displayMenu() {
    std::cout << "Product Maintenance" << std::endl;
    std::cout << "1. List products\n"
                 "2. Add product\n"
                 "3. Edit product\n"
                 "4. Delete product\n"
                 "5. Back\n"
                 "Enter your choice: ";
}

void CLIStateProductMaintenance::handleUserInput() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
            break;
        }
        case 2: {
            IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
            std::string name;
            double price;
            std::string description;
            long stock;
            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter product price: ";
            std::cin >> price;
            std::cout << "Enter product description: ";
            std::cin >> description;
            std::cout << "Enter product stock: ";
            std::cin >> stock;
            productRepository.addProduct(name, description, price, stock);
            std::cout << "Product added" << std::endl;
            break;
        }
        case 3: {
            productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
            int productId;
            std::cout << "Enter product id: ";
            std::cin >> productId;
            IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
            std::optional<Product> product = productRepository.getProduct(productId);
            if (!product.has_value()) {
                std::cout << "Product not found" << std::endl;
                break;
            }
            std::cout << "Product Info:\n";
            std::cout << product->getId() << " " << product->getName() << " " << product->getPrice() << " "
                      << product->getRemainingStock() << std::endl;
            std::string name;
            double price;
            std::string description;
            long stock;
            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter product price: ";
            std::cin >> price;
            std::cout << "Enter product description: ";
            std::cin >> description;
            std::cout << "Enter product stock: ";
            std::cin >> stock;
            product->setName(name);
            product->setPrice(price);
            product->setDescription(description);
            product->setRemainingStock(stock);
            productRepository.updateProduct(*product);
            std::cout << "Product updated" << std::endl;
            break;
        }
        case 4: {
            productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
            int productId;
            std::cout << "Enter product id: ";
            std::cin >> productId;
            IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
            if (!productRepository.deleteProduct(productId)) {
                std::cout << "Product not found" << std::endl;
                break;
            }
            std::cout << "Product deleted" << std::endl;
            break;
        }
        case 5: {
            userInterface.popState();
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
}
