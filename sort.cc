#include"list_products.hh"
#include"products_db.hh"
#include"sort.hh"
#include<iostream>
#include<vector>
#include<algorithm>

void SortProducts::exec(){
    std::vector<Product> ref_prod_database; 
    ref_prod_database = ProductsDatabase::products_database;
    int ans;
    std::string s_ans;
    std::cout << "[1] From the cheapest to the most expensive\n[2] from the most expensive to the cheapest\n";
    std::getline(std::cin,s_ans);
    ans=std::stoi(s_ans);
    if (ans == 2)
    {
        sort(ref_prod_database.begin(), ref_prod_database.end(), [](const Product& lhs, const Product& rhs) {
        return lhs.price > rhs.price;
        });
    }
    else if (ans == 1)
    {
        sort(ref_prod_database.begin(), ref_prod_database.end(), [](const Product& lhs, const Product& rhs) {
        return lhs.price < rhs.price;
        });
    }
    else 
        return;
    
    for(auto i = ref_prod_database.begin(); i != ref_prod_database.end(); i++)
    {
       std::cout<<"id: "<< i->id <<"; name: "<< i->name << "; date: " << i->creation_date << "; price: " << i->price << "; quantity: " << i->stock << ";\n";
    }
    std::cout<<"End\n>";
 } 