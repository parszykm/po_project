#include"delete_promo.hh"
#include"products_db.hh"
#include"promo_db.hh"
#include<iostream>
#include<algorithm>

void DeletePromo::exec(){
    std::string s_id;
    std::cout<<"Pass promotion id to be deleted: ";
    std::getline(std::cin, s_id);
    int id=std::stoi(s_id);
    auto it=find_if(PromoDatabase::promotion_database.begin(),PromoDatabase::promotion_database.end(),[&id](const Promotion obj){return obj.promo_id==id;});
    if(it != PromoDatabase::promotion_database.end()){
        
        auto it2=find_if(ProductsDatabase::products_database.begin(),ProductsDatabase::products_database.end(),[&it](const Product obj){return obj.id==it->id;});
        if(it2!=ProductsDatabase::products_database.end()){ 
            it2->price+=it->promo;

        }
        PromoDatabase::promotion_database.erase(it);
    }
    else{
        std::cout<<"There is no promotion with such an id...\n";
    }

    std::cout<<"End\n>";
}