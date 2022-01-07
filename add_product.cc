#include<iostream>
#include<string>
#include<sstream>
#include"add_product.hh"
#include"products_db.hh"
#include"product.hh"

void AddProduct::exec(){
    std::string name;
    std::string creation_date;
    std::cout<<"Type in product name\n";
    std::getline(std::cin,name);
    std::cout<<"Type in date\n";
    std::getline(std::cin,creation_date);
    Product tmp;
    // tmp.id=1;
    // tmp.name=name;
    // tmp.creation_date=creation_date;
    ProductsDatabase::products_database.push_back({1,name,creation_date});
    std::cout<<"Product Added\n>";




}