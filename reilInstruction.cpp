#include<vector>
#include<string>
#include<iostream>

#include"operations.h"
#include"reilInstruction.h"
#include"operands.h"

ReilInstruction::ReilInstruction(Operations op, std::vector<Operands> operands ):op(op),operands(operands){
    
}

ReilInstruction::~ReilInstruction()
{
}

std::ostream& operator<<(std::ostream& stream, const ReilInstruction& reilInsn){
    stream<<"\t"<<reilInsn.op.op;
    int i = 1;
    for(; i < reilInsn.operands.size(); i++){
        //std::cout<<"What the fuck: "<<i<<std::endl;
        stream<<(std::string)"\t"<<reilInsn.operands[i];
    }
    stream<<(std::string)"\t"<<reilInsn.operands[0]<<std::endl;
    return stream;
}