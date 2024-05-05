//
// Created by chi on 24/05/01.
//

#include <iostream>
#include "CLIStateProductMaintenance.h"

CLIStateProductMaintenance::CLIStateProductMaintenance(CLIUserInterface &userInterface) : userInterface(userInterface) {
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
            listProducts();
            break;
        }
        case 2: {
            IProductRepository &productRepository = userInterface.getProductRepository();
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
            listProducts();
            int productId;
            std::cout << "Enter product id: ";
            std::cin >> productId;
            IProductRepository &productRepository = userInterface.getProductRepository();
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
            listProducts();
            int productId;
            std::cout << "Enter product id: ";
            std::cin >> productId;
            IProductRepository &productRepository = userInterface.getProductRepository();
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

void CLIStateProductMaintenance::listProducts() {
    IProductRepository &productRepository = userInterface.getProductRepository();
    std::vector<Product> products = productRepository.listProducts();
    std::cout << "Product List" << std::endl;
    std::cout << "ID Name Price Stock" << std::endl;
    for (const Product &product: products) {
        std::cout << product.getId() << " " << product.getName() << " " << product.getPrice() << " "
                  << product.getRemainingStock() << std::endl;
    }
    std::cout << std::endl;
}
