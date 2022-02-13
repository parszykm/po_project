#pragma once

#include"product.hh"
class Shoe: public Product{
    public:

        // std::string size;
        void setType(){
            this->type="shoes";
        }
        void initSize();
        Shoe(std::string name, std::string date, int price, int stock, std::string size):Product(name, date, price, stock,size){}



};