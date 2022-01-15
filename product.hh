#pragma once

#include<string>
class Product{
    public:
        static int count;
        int id;
        std::string name;
        int price;
        std::string creation_date;
        Product(std::string name, std::string date, int price ): id(this->count), name(name),price(price),creation_date(date){}

        
};