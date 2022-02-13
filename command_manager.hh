#pragma once

#include<map>
#include<string>
#include "command.hh"
class CommandManager{
    std::map<std::string, command> commands_admin;
    std::map<std::string, command> commands_user;
    public:
        CommandManager();
        void loop();
};
