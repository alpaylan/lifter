#ifndef LIFTER
#define LIFTER

#include<string>
#include<vector>
#include"instruction.h"
#include"reilInstruction.h"
#include"rawInstruction.h"

class Lifter{
private:
    /* data */
public:
    //Constructors and Destructors
    std::vector<ReilInstruction> reilInsn;
    Lifter();
    ~Lifter();
    //Functions
    std::vector<Operands> rawOperandToReil(std::vector<Operands> operands);
    void turnRawToReil(Instruction &rawInsn);
    friend std::ostream& operator<<(std::ostream& stream, const Lifter& lifter);
};

#endif