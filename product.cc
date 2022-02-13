#include"product.hh"
int Product::count=0;

std::string Product::getType(){
    return this->type;
}
std::string Product::getSize(){
    return this->size;
}