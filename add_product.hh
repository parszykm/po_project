#pragma once

#include"command.hh"
#include"product.hh"

class AddProduct: public Command{
    public:
        void exec();

};