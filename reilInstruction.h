#ifndef REIL_INSTRUCTIONS
#define REIL_INSTRUCTIONS

#include<vector>

#include"operands.h"
#include"operations.h"

class ReilInstruction{
private:
    
public:
    Operations op;
    std::vector<Operands> operands;
    ReilInstruction(Operations operation, std::vector<Operands> operands);
    ~ReilInstruction();
    friend std::ostream& operator<<(std::ostream& stream, const ReilInstruction& reilInsn);
};

#endif
