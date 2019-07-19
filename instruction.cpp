#include<iostream>
#include<algorithm>

#include"instruction.h"

Instruction::Instruction(std::string input){
    auto instructions = parseInput(input);
    for(auto i: instructions){
        //std::cout<<"i: "<<i<<std::endl;
        this->parseInstruction(i);
    }
}

Instruction::~Instruction(){
}

std::vector<std::string> Instruction::parseInput(std::string input){
    std::vector<std::string> instructions;
    while(true){
        auto endArg = input.find('\n');
        if(endArg == std::string::npos){
            break;
        }
        instructions.push_back(input.substr(0,endArg));

        input = input.substr(endArg + 1);
        //std::cout<<"Input : "<<input<<std::endl;
        instructions.push_back(input);
    }
    if(instructions.empty()){
        //std::cout<<"Input : "<<input<<std::endl;
        instructions.push_back(input);
    }
    return instructions;
}


void Instruction::parseInstruction(std::string input){
    //std::cout<<"Input: "<<input<<std::endl; 
    auto firstSpace = input.find(' ');
    std::string operation = input.substr(0, firstSpace);
    std::string operands = input.substr(firstSpace+1);
    //std::cout<<"firstSpace: "<<firstSpace<<std::endl;
    operation.erase(remove_if(operation.begin(), operation.end(), isspace), operation.end());
    //std::cout<<"operation: "<<operation<<std::endl;
    //std::cout<<"operation == ADD: "<<(operation == "ADD")<<std::endl;
    operands.erase(remove_if(operands.begin(), operands.end(), isspace), operands.end());
    //std::cout<<"operands: "<<operands<<std::endl;
    std::vector<Operands> parsedOperands;
    while(true){
        auto endArg = operands.find(',');
        parsedOperands.push_back(Operands(operands.substr(0,endArg)));
        if(endArg == std::string::npos){
            break;
        }
        operands = operands.substr(endArg + 1);
        
    }
    instructions.push_back(RawInstruction(operation, parsedOperands));
    /* 
    std::cout<<"operation: "<<operation<<std::endl;
    for(auto i : parsedOperands){
        std::cout<<"parsedOperands: "<<i<<std::endl;
    }
    */
    
}

std::ostream& operator<<(std::ostream& stream, const Instruction& insn){
    for(auto i: insn.instructions){
        stream<<i;
    }
    return stream;
}