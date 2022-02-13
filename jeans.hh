#pragma once

#include"product.hh"
class Jeans: public Product{
    public:

        void setType(){
            this->type="jeans";
        }
        void initSize();
        Jeans(std::string name, std::string date, int price, int stock, std::string size):Product(name, date, price, stock,size){}



};