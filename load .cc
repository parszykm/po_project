#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


#include "load_db.hh"
#include "products_db.hh"

void LoadfromFile::exec() {
    std::ifstream in("product_db.txt");
    decltype(ProductsDatabase::products_database) products;
    std::string row;
    while (std::getline(in, row)) {
        std::stringstream ss(row);
        std::string name;
        std::string creation_date;
        std::string s_stock;
        std::string s_price;
        std::string s_id;
        std::string type;
        std::string size;
        int stock,price,id;
        std::getline(ss, s_id, ';');
        std::getline(ss, type, ';');
        std::getline(ss, name, ';');
        std::getline(ss, size, ';');
        std::getline(ss, creation_date, ';');
        std::getline(ss, s_price, ';');
        std::getline(ss, s_stock, ';');
        price=std::stoi(s_price);
        stock=std::stoi(s_stock);
        id=std::stoi(s_id);


        Product::count++;
        Product tmp(id,name,creation_date,price,stock,size,type);
        Product::count=id+1;
        products.push_back(tmp);
    }
    ProductsDatabase::products_database = std::move(products);
    std::cout << "Database loaded from file\n>";
}