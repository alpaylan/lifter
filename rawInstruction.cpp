#include<string>
#include<iostream>
#include"rawInstruction.h"

RawInstruction::RawInstruction(Operations operation, std::vector<Operands> operands):op(operation), operands(operands){
}

RawInstruction::~RawInstruction(){

}

std::ostream& operator<<(std::ostream& stream, const RawInstruction& rawInsn){
    stream<<rawInsn.op<<std::string("\t");
    for(auto i: rawInsn.operands){
        stream<<std::string("\t")<<i;
    }
    stream<<std::endl;
return stream;
}