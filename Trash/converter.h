#include<vector>
#include<string>
#include<z3++.h>

#include"reilInstruction.h"

class Converter
{
private:
    
public:
    Converter();
    ~Converter();
    bool checkEqualityOfAdd(std::vector<ReilInstruction> reilInsns1, std::vector<ReilInstruction> reilInsns2);
    z3::expr createExpr(std::string expression, z3::context &c);
};

