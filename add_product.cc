#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<ctime>
#include"add_product.hh"
#include"products_db.hh"
#include"product.hh"
#include"jacket.hh"
#include"shoe.hh"
#include"jeans.hh"
#include <cctype>
#include<algorithm>


void AddProduct::exec(){
    std::string name;
    std::string creation_date;
    std::string s_price,s_stock,type,size;
    int price,stock;
    time_t now=time(0);
    std::string dt = ctime(&now);
    std::cout<<"Type in product type\n";
    std::getline(std::cin,type);
    std::cout<<"Type in product name\n";
    std::getline(std::cin,name);
    // std::cout<<"Type in date\n";
    // std::getline(std::cin,creation_date);
    std::cout<<"Type in price\n";
    std::getline(std::cin,s_price);
    std::cout<<"Type in size\n";
    std::getline(std::cin,size);
    std::stringstream ss(s_price);
    ss>>price;
    std::cout<<"Type in quantity of this product in stock\n";
    std::getline(std::cin,s_stock);
    std::stringstream ss2(s_stock);
    ss2>>stock;
    dt.erase(dt.end()-1,dt.end());
    //Product tmp(name,dt,price,stock);
    std::transform(type.begin(), type.end(), type.begin(),
    [](unsigned char c){ return std::tolower(c); });
    if(type=="jacket"){
        Jacket tmp(name,dt,price,stock,size);
        tmp.setType();
        Product::count++;
        ProductsDatabase::products_database.push_back(tmp);
    }
    if(type=="shoes"){
        Shoe tmp(name,dt,price,stock,size);
        tmp.setType();
        Product::count++;
        ProductsDatabase::products_database.push_back(tmp);
    }
    if(type=="jeans"){
        Jeans tmp(name,dt,price,stock,size);
        tmp.setType();
        Product::count++;
        ProductsDatabase::products_database.push_back(tmp);
    }
    // else{
    //     Product tmp(name,dt,price,stock,size);
    //     tmp.setType();
    //     Product::count++;
    //     ProductsDatabase::products_database.push_back(tmp);

    // }


    std::cout<<"Product Added\n>";




}