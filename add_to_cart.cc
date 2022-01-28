#include<iostream>
#include"add_to_cart.hh"
#include"cart.hh"
#include"products_db.hh"
#include<algorithm>
#include<ctime>
#include<string>

void AddToCart::exec(){
    std::string s_id,s_amount;
    std::cout<<"Pass id of the product: \n";
    std::getline(std::cin,s_id); 
    std::cout<<"Pass amount: \n";
    int id=std::stoi(s_id); 
    std::getline(std::cin, s_amount);
    int amount=std::stoi(s_amount);
    auto it=find_if(ProductsDatabase::products_database.begin(),ProductsDatabase::products_database.end(), [&id](const Product& obj){return obj.id==id;});
    if(it!=Cart::cart.end()){
        it->stock-amount >0 ? it->stock-=amount :(amount=it->stock, it->stock=0);
        time_t now=time(0);
        std::string dt = ctime(&now); 
        Product tmp(it->name,dt,it->price*amount,amount);
        tmp.id=id;
        Cart::cart.push_back(tmp);
    }
    else{
        std::cout<<"There is no such a product...\n";
    }

    std::cout<<"Item added\n>";

}