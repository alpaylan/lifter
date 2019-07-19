#include<iostream>
#include<string>
#include"operations.h"

Operations::Operations(std::string operation){
    //std::cout<<"Operation in operations.cpp: "<<operation<<std::endl;
    if(contains(operation)){
        op = operation;
    }
    else{
        std::cout<<"No such operation exists"<<std::endl;

    }
}
Operations::~Operations(){
    allowedOperations.clear();
}

bool Operations::contains(std::string operation){
    for(auto i : allowedOperations){
        if(i == operation){
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& stream, const Operations& operation){
    stream<<operation.op;
    return stream;
}