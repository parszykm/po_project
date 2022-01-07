#pragma once

#include<map>
#include<string>
#include "command.hh"
class CommandManager{
    std::map<std::string, command> commands;
    public:
        CommandManager();
        void loop();
};
