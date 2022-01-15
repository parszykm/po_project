#include<iostream>
#include"list_promo.hh"
#include"promo_db.hh"
void ListPromo::exec(){
    for(auto promo: PromoDatabase::promotion_database){
        std::cout<<"id: "<< promo.promo_id<<"; prod_id: "<<promo.id<<";promo: "<<promo.promo<<";\n";

    }
    std::cout<<"End\n>";
}