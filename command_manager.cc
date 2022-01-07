#include<iostream>
#include"command_manager.hh"
#include"add_product.hh"
#include"list_products.hh"
#include"exit.hh"

CommandManager::CommandManager()
{
    commands["add"]=std::make_shared<AddProduct>();
    commands["list"]=std::make_shared<ListProducts>();
    commands["exit"]=std::make_shared<ExitCommand>();
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