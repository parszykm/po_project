#pragma once

#include<string>
class Product{
    protected:
        std::string type;
        std::string size;
    public:
        static int count;
        int id;
        std::string name;
        int price;
        std::string creation_date;
        int stock;

        virtual void setType(){
            this->type="Unisex";
        }
        std::string getType();
        std::string getSize();
        Product(std::string name, std::string date, int price, int stock ): id(this->count), name(name),price(price),creation_date(date), stock(stock){}
        Product(int id,std::string name, std::string date, int price, int stock,std::string size,std::string type ): id(id), size(size),type(type),name(name),price(price),creation_date(date), stock(stock){}
        Product(int id,std::string name, std::string date, int price, int stock ): id(id), name(name),price(price),creation_date(date), stock(stock){}
        Product(std::string name, std::string date, int price, int stock, std::string size ): id(this->count), name(name),price(price),creation_date(date), stock(stock), size(size){}
        
};
