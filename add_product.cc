#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<ctime>
#include"add_product.hh"
#include"products_db.hh"
#include"product.hh"

void AddProduct::exec(){
    std::string name;
    std::string creation_date;
    std::string s_price;
    int price;
    time_t now=time(0);
    std::string dt = ctime(&now);
    std::cout<<"Type in product name\n";
    std::getline(std::cin,name);
    // std::cout<<"Type in date\n";
    // std::getline(std::cin,creation_date);
    std::cout<<"Type in price\n";
    std::getline(std::cin,s_price);
    std::stringstream ss(s_price);
    ss>>price;
    dt.erase(dt.end()-1,dt.end());
    Product tmp;
    tmp.id=tmp.count++;
    tmp.name=name;
    tmp.creation_date=dt;
    tmp.price=price;
    ProductsDatabase::products_database.push_back(tmp);
    std::cout<<"Product Added\n>";




}