#include"exit.hh"
#include<iostream>
#include<cstdlib>
void ExitCommand::exec(){
    std::cout<<"Exiting app...\n";
    exit(0);
}