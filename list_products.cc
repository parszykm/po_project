#include"list_products.hh"
#include"products_db.hh"
#include<iostream>
 void ListProducts::exec(){
     for(int i=0;i<ProductsDatabase::products_database.size();i++)
     {
        std::cout<<"id: "<<ProductsDatabase::products_database[i].id<<"; type: "<<ProductsDatabase::products_database[i].getType()<<"; name: "<<ProductsDatabase::products_database[i].name<<
        "; size: "<<ProductsDatabase::products_database[i].getSize()<<"; date: "<<ProductsDatabase::products_database[i].creation_date<<
        "; price: "<<ProductsDatabase::products_database[i].price<<"; quantity: "<<ProductsDatabase::products_database[i].stock<<";\n";
     }
     std::cout<<"End\n>";
 } 

