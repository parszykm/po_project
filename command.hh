#pragma once
#include<memory>

class Command{
    public:
        virtual void exec()=0;

};

using command= std::shared_ptr<Command>;