#include"delete_product.hh"
#include"products_db.hh"
#include"product.hh"
#include<iostream>
#include <algorithm>

void DeleteProduct::exec(){
    std::string s_index;
    std::cout<<"Item of which id do you want to delete?\n ";
    std::getline(std::cin,s_index);
    int index=std::stoi(s_index);
    auto it=find_if(ProductsDatabase::products_database.begin(),ProductsDatabase::products_database.end(),[&index](const Product& obj){return obj.id == index;});
    std::cout<<it->name<<"\n";
    if(it != ProductsDatabase::products_database.end())
    {
        ProductsDatabase::products_database.erase(it);
        std::cout<<"Item with id: "<<index<<" deleted\n>";
    }
    else{
        std::cout<<"No item with "<<index<<" id\n>";
    }
    

}