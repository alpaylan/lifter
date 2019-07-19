#ifndef RAW_INSTRUCTIONS
#define RAW_INSTRUCTIONS

#include<vector>

#include"operands.h"
#include"operations.h"

class RawInstruction
{
private:

public:
    Operations op;
    std::vector<Operands> operands;
    RawInstruction(Operations operation, std::vector<Operands> operands);
    ~RawInstruction();
    friend std::ostream& operator<<(std::ostream& stream, const RawInstruction& rawInsn);
};

#endif