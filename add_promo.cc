#include"add_promo.hh"
#include"products_db.hh"
#include"product.hh"
#include"promo_db.hh"
#include<iostream>
#include<algorithm>

void AddPromo::exec(){
    std::string s_id;
    std::string s_price;
    std::string s_time;
    std::cout<<"Pass id of discounted product: ";
    std::getline(std::cin, s_id);
    std::cout<<"Pass the discount value: ";
    std::getline(std::cin, s_price);
    int id,price;
    id=std::stoi(s_id);
    price=std::stoi(s_price);
    auto it=find_if(ProductsDatabase::products_database.begin(),ProductsDatabase::products_database.end(),[&id](const Product& obj){return obj.id == id;});
    Promotion tmp(it->name,it->price,it->creation_date);
    if(it->price-price<0){  
        tmp.promo=it->price;
        it->price=0;
    }
    else{
        tmp.promo=price;
        it->price-=price; 
    }
    tmp.promo_id=tmp.promo_id_count++;   
    PromoDatabase::promotion_database.push_back(tmp);
    
    std::cout<<"Discount added...\n>";


}