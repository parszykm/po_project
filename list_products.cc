#include"list_products.hh"
#include"products_db.hh"
#include<iostream>
 void ListProducts::exec(){
     for(int i=0;i<ProductsDatabase::products_database.size();i++)
     {
         std::cout<<i<<"\n"<<ProductsDatabase::products_database[i].name<<ProductsDatabase::products_database[i].creation_date<<"\n";
     }
     std::cout<<"End\n>";
 } 