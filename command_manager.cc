#include<iostream>
#include<string.h>
#include"command_manager.hh"
#include"add_product.hh"
#include"list_products.hh"
#include"delete_product.hh"
#include"add_promo.hh"
#include"list_promo.hh"
#include"delete_promo.hh"
#include"add_to_cart.hh"
#include"show_cart.hh"
#include"delete_from_cart.hh"
#include"save.hh"
#include"load_db.hh"
#include"filter.hh"
#include"sort.hh"
#include<algorithm>
#include<sstream>
#include<vector>
#include<fstream>

CommandManager::CommandManager()
{
    commands_admin["add"]=std::make_shared<AddProduct>();
    commands_admin["list"]=std::make_shared<ListProducts>();
    commands_admin["del"]=std::make_shared<DeleteProduct>();
    commands_admin["promo"]=std::make_shared<AddPromo>();
    commands_admin["lpromo"]=std::make_shared<ListPromo>();
    commands_admin["dpromo"]=std::make_shared<DeletePromo>();
    commands_admin["addcart"]=std::make_shared<AddToCart>();
    commands_admin["show"]=std::make_shared<ShowCart>();
    commands_admin["delcart"]=std::make_shared<DeleteCart>();
    commands_admin["save"]=std::make_shared<SavetoFile>();
    commands_admin["sort"]=std::make_shared<SortProducts>();
    commands_admin["filter"]=std::make_shared<Filter>();
    commands_admin["load"]=std::make_shared<LoadfromFile>();

    commands_user["list"]=std::make_shared<ListProducts>();
    commands_user["addcart"]=std::make_shared<AddToCart>();
    commands_user["show"]=std::make_shared<ShowCart>();
    commands_user["delcart"]=std::make_shared<DeleteCart>();
    commands_user["sort"]=std::make_shared<SortProducts>();
    commands_user["filter"]=std::make_shared<Filter>();
}

void CommandManager::loop(){
    std::map<std::string, command> commands;
    std::string option, log, login, password;
    std::vector<std::vector<std::string>> loging;
    time_t start, end;
    std::ifstream in("admins.txt");
    std::string row;
    while (std::getline(in, row)) {
        std::vector<std::string> v;
        std::stringstream ss(row);
        std::string l;
        std::string pass;
        std::getline(ss, l, ':');
        ss >> pass;
        v.push_back(l);
        v.push_back(pass);
        loging.push_back(v);
    }
    std::cout<<"Use 'admin' for login as admin or 'user' for countinue as user\n>";
    while(std::getline(std::cin, log)){
        if(!strcmp(log.c_str(), "user")){
            commands = commands_admin;
            commands_admin["load"]->exec();
            commands = commands_user;
            break;
        }
        else if(!strcmp(log.c_str(), "admin")){
            std::cout << "Pass login\n>";
            std::getline(std::cin, login);
            std::cout << "Pass password\n>";
            std::getline(std::cin, password);
            std::vector<std::string> i{login, password};
            auto it = std::find(loging.begin(), loging.end(), i);
            if(it != loging.end()){
                std::cout << "Logged succesfully\n";
                commands = commands_admin;
                break;
            }
            else{
                std::cout << "Error..\n";
            }
        }
        else{
            std::cout<<"Passed '"<<option<<"' isn't correct. Try again...\n>";
        }
    }
    time(&start);
    std::cout<<">";
    while(std::getline(std::cin,option)){
        if(!strcmp(option.c_str(), "exit"))
            break;
        if(commands.find(option)!=commands.end()){
            commands[option]->exec();
        }
        else{
            std::cout<<"Passed '"<<option<<"' does not exist...\n>";
        }
    }
    time(&end);
    double time_taken = double(end - start);
    std::cout << "Your shopping session took " << time_taken << " sec\n";
}