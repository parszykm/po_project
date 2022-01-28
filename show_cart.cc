#include<iostream>

#include"cart.hh"
#include"show_cart.hh"
#include <numeric>     
void ShowCart::exec(){
    for(auto kv: Cart::cart)
    {
        std::cout<<"id: "<<kv.id<<"; name: "<<kv.name<<"; amount: "<<kv.stock<<"; price: "<<kv.price<<";\n";
        
    }
    int init=0;
    int all_cost=std::accumulate(Cart::cart.begin(),Cart::cart.end(), init,[](int x, const Product& obj){return x+obj.price;});
    std::cout<<"Total "<<all_cost<<std::endl;
    std::cout<<"End\n>";
}