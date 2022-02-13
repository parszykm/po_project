#pragma once

#include"product.hh"
class Jacket: public Product{
    public:

        // std::string size;
        void setType(){
            this->type="jacket";
        }
        Jacket(std::string name, std::string date, int price, int stock, std::string size):Product(name, date, price, stock,size){}
        void setSize(){
            this->size=size;
        }



};