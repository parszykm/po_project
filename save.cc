#include <iostream>
#include <fstream>

#include "save.hh"
#include "products_db.hh"

void SavetoFile::exec() {
    std::ofstream out("product_db.txt");
    for (auto &&prod: ProductsDatabase::products_database) {
        out << prod.id << ";" <<prod.getType()<<";"<< prod.name <<";"<<prod.getSize()<< ";" << prod.creation_date << ";" << prod.price << ";" << prod.stock << "\n"; 
    }
    out.close();
    std::cout << "Products saved to file...\n>";
}