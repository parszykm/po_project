#pragma once

#include"product.hh"
class Promotion: public Product{
    public:
        Promotion(std::string name,int price,std::string date) : Product(name,date,price){}
        static int promo_id_count;
        int promo_id;
        int promo;
        
    
};