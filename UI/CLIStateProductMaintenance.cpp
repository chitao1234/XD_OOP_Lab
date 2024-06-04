//
// Created by chi on 24/05/01.
//

#include <iostream>
#include "CLIStateProductMaintenance.h"
#include "Service/StorageService.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    using Service::StorageService;

    CLIStateProductMaintenance::CLIStateProductMaintenance(CLIUserInterface &userInterface) :
            userInterface(userInterface),
            productDisplay(StorageService::getInstance()->getProductRepository().listProducts()) {
    }

    void CLIStateProductMaintenance::displayMenu() {
        productDisplay.setProducts(StorageService::getInstance()->getProductRepository().listProducts());
        std::cout << "Product Maintenance" << std::endl;
        std::cout << "1. List products\n"
                     "2. Add product\n"
                     "3. Edit product\n"
                     "4. Delete product\n"
                     "5. Set product discount\n"
                     "6. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateProductMaintenance::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        DataAccess::IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
        switch (choice) {
            case 1: {
                productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
                break;
            }
            case 2: {
                std::string name;
                double price;
                std::string description;
                long stock;
                std::string category;
                std::cout << "Enter product name: ";
                Util::cinWrapper >> name;
                std::cout << "Enter product price: ";
                Util::cinWrapper >> price;
                std::cout << "Enter product description: ";
                Util::cinWrapper >> description;
                std::cout << "Enter product stock: ";
                Util::cinWrapper >> stock;
                std::cout << "Enter product category:";
                Util::cinWrapper >> category;
                productRepository.addProduct(name, description, price, stock, category);
                std::cout << "Product added" << std::endl;
                break;
            }
            case 3: {
                // 显示商品列表，选择商品
                productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
                int productId;
                std::cout << "Enter product id: ";
                Util::cinWrapper >> productId;
                std::optional<DataType::FullProduct> product = productRepository.getProduct(productId);
                if (!product.has_value()) {
                    std::cout << "Product not found" << std::endl;
                    break;
                }

                // 显示商品信息，修改商品信息
                std::cout << "Product Info:\n";
                std::cout << "ID: " << product->getId() << '\n'
                          << "Name: " << product->getName() << '\n'
                          << "Price: " << product->getPrice() << '\n'
                          << "Description: " << product->getDescription() << '\n'
                          << "Discount: " << product->getDiscount() << '\n'
                          << "Category: " << product->getCategory() << std::endl;
                std::string name;
                double price;
                std::string description;
                long stock;
                std::string category;
                std::cout << "Enter product name: ";
                Util::cinWrapper >> name;
                std::cout << "Enter product price: ";
                Util::cinWrapper >> price;
                std::cout << "Enter product description: ";
                Util::cinWrapper >> description;
                std::cout << "Enter product stock: ";
                Util::cinWrapper >> stock;
                std::cout << "Enter product category:";
                Util::cinWrapper >> category;
                product->setName(name);
                product->setPrice(price);
                product->setDescription(description);
                product->setRemainingStock(stock);
                product->setCategory(category);
                productRepository.updateProduct(*product);
                std::cout << "Product updated" << std::endl;
                break;
            }
            case 4: {
                productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
                int productId;
                std::cout << "Enter product id: ";
                Util::cinWrapper >> productId;
                if (!productRepository.deleteProduct(productId)) {
                    std::cout << "Product not found" << std::endl;
                    break;
                }
                std::cout << "Product deleted" << std::endl;
                break;
            }
            case 5: {
                // 实现商品折扣功能
                productDisplay.listProducts(ProductDisplay::DETAILED_WITH_STOCK);
                int productId;
                std::cout << "Enter product id: ";
                Util::cinWrapper >> productId;
                std::optional<DataType::FullProduct> product = productRepository.getProduct(productId);
                if (!product.has_value()) {
                    std::cout << "Product not found" << std::endl;
                    break;
                }
                double discount;
                std::cout << "Enter discount: ";
                Util::cinWrapper >> discount;
                product->setDiscount(discount);
                productRepository.updateProduct(*product);
                std::cout << "Discount set" << std::endl;
                break;
            }
            case 6: {
                userInterface.popState();
                break;
            }
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
}
