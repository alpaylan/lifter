#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<iomanip>

#include"lifter.h"
#include"rawInstruction.h"

Lifter::Lifter(){}
Lifter::~Lifter(){}

void Lifter::turnRawToReil(Instruction &insn){
    for(auto i : insn.instructions){
        auto reilOperands = this->rawOperandToReil(i.operands);
        //std::cout<<"i.op: "<<i.op.op<<std::endl;
        this->reilInsn.push_back(ReilInstruction(i.op, reilOperands));
    }

}

std::vector<Operands> Lifter::rawOperandToReil(std::vector<Operands> operands){
    std::vector<Operands> reilOperands; 
    for(auto i : operands){
        if(i.type == 'R' || i.type == 'V'){
            reilOperands.push_back(Operands(i.type + (std::string)"_" + i.name));
        }   
        else if(i.type == 'I'){
            int decimal = std::stoi(i.name.substr(1));
            std::stringstream ss;
            ss<< std::hex << decimal; 
            std::string res ( ss.str() );
            reilOperands.push_back(Operands("0x" + res));
        }
        else if(i.type == 'U'){
            std::cout<<"Unknown or undefined operand type"<<std::endl;
        }
        else {
            std::cout<<"There is an error"<<std::endl;
        }
        
    }
    return reilOperands;
}
std::ostream& operator<<(std::ostream& stream, const Lifter& lifter){
    for(int i = 0; i< lifter.reilInsn.size() ; i++){
        stream<<"000000."<< std::setw(2)<<std::setfill('0')<<i<<lifter.reilInsn[i];
    }
    return stream;
}
