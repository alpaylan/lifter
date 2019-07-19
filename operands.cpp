#include<iostream>
#include<string>
#include"operands.h"

bool Operands::contains(std::string registerToCheck){
    for(auto i: this->allowedRegisters){
        if(registerToCheck == i)
            return true;
    }
    return false;
}
Operands::Operands(std::string operandName){
    name = operandName;
    
    if(operandName[0] == 'R' || this->contains(operandName)){
        type = 'R';
    }
    else if(operandName[0] == '#' || operandName.substr(0,2) == "0x"){
        type = 'I';
    }
    else {
        type = 'U';
    }
}
Operands::~Operands(){
    allowedRegisters.clear();
}


std::string Operands::getValue(){
    if(this->type == 'I'){
        if(this->name[0] == '#'){
            return this->name.substr(1);
        }
        else if(this->name.substr(0,2) == "0x"){
            return this->name;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
    
}
std::ostream& operator<<(std::ostream& stream, const Operands& operand){
    stream<<operand.name;
    return stream;
}