#ifndef INSTRUCTION
#define INSTRUCTION

#include<vector>
#include<string>

#include"rawInstruction.h"

class Instruction
{
private:
    
public:
    std::vector<RawInstruction> instructions;
    Instruction(std::string input);
    ~Instruction();
    std::vector<std::string> parseInput(std::string input);
    void parseInstruction(std::string input);
    friend std::ostream& operator<<(std::ostream& stream, const Instruction& insn);
};

#endif