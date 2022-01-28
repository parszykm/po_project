#include"delete_from_cart.hh"
#include"products_db.hh"
#include"cart.hh"
#include<iostream>
#include<algorithm>

void DeleteCart::exec(){
    std::string s_id;
    std::cout<<"Pass product id to be deleted: ";
    std::getline(std::cin, s_id);
    int id=std::stoi(s_id);
    auto it=find_if(Cart::cart.begin(),Cart::cart.end(),[&id](const Product obj){return obj.id==id;});
    if(it != ProductsDatabase::products_database.end()){
        
        auto it2=find_if(ProductsDatabase::products_database.begin(),ProductsDatabase::products_database.end(),[&it](const Product obj){return obj.id==it->id;});
        if(it2!=ProductsDatabase::products_database.end()){ 
            it2->stock+=it->stock;

        }
        Cart::cart.erase(it);
    }
    else{
        std::cout<<"There is no product with such an id in cart...\n";
    }

    std::cout<<"End\n>";
}