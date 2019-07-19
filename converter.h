#include<vector>
#include<string>
#include<z3++.h>
#include<map>
#include<vector>
#include<utility>

#include"reilInstruction.h"
#include"operands.h"
class Converter
{
private:
    
public:
    std::map< Operands , std::pair<z3::expr , z3::expr> > regExprMap;
    z3::context c;
    Converter();
    ~Converter();
    bool checkEquality(z3::expr e1, z3::expr e2);
    z3::expr createExpr(std::string e);
    void loadMap(std::vector<ReilInstruction> rInsns1 , std::vector<ReilInstruction> rInsns2);

};

