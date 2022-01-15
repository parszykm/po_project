#include<iostream>
#include"command_manager.hh"
#include"add_product.hh"
#include"list_products.hh"
#include"exit.hh"
#include"delete_product.hh"
#include"add_promo.hh"
#include"list_promo.hh"
#include"delete_promo.hh"

CommandManager::CommandManager()
{
    commands["add"]=std::make_shared<AddProduct>();
    commands["list"]=std::make_shared<ListProducts>();
    commands["exit"]=std::make_shared<ExitCommand>();
    commands["del"]=std::make_shared<DeleteProduct>();
    commands["promo"]=std::make_shared<AddPromo>();
    commands["lpromo"]=std::make_shared<ListPromo>();
    commands["dpromo"]=std::make_shared<DeletePromo>();
}
void CommandManager::loop(){
    std::string option;
    std::cout<<">";
    while(std::getline(std::cin,option)){
        if(commands.find(option)!=commands.end()){
            commands[option]->exec();

        }
        else{
            std::cout<<"Passed '"<<option<<"' does not exist...\n>";
        }
    }

}