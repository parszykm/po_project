#include"filter.hh"
#include"products_db.hh"
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
void Filter::exec(){
    std::vector<std::string> types;
    std::vector<std::string> sizes;
    std::cout<<"Type in types filter\n";
    std::string row,tmp;
    std::getline(std::cin,row);
    std::transform(row.begin(), row.end(),  row.begin(), [](unsigned char c){ return std::tolower(c); });
    std::stringstream ss(row);
    while(!ss.eof()){
        ss>>tmp;
        types.push_back(tmp);
    }
    std::cout<<"Type in size filter\n";
    std::getline(std::cin,row);
    std::stringstream ss2(row);
    while(!ss2.eof()){
        ss2>>tmp;
        sizes.push_back(tmp);
    }
    for (auto &&prod: ProductsDatabase::products_database) {
        for(int j=0;j<types.size();j++){
            if(prod.getType()==types[j]){
                for(int k=0;k<sizes.size();k++){
                    if(prod.getSize()==sizes[k]){
                        std::cout<<"id: "<<prod.id<<" name: "<<prod.name<<" size: "<<prod.getSize()<<" price: "<<prod.price<<"\n";
                    }
                }
            }
        }

    }
    std::cout<<"End\n>";
}