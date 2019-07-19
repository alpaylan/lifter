#include"converter.h"

using namespace z3;

Converter::Converter(){}

Converter::~Converter(){}

bool Converter::checkEquality(z3::expr e1, z3::expr e2){
    solver s(c);

    expr e3 = (e1 == e2);

    s.add(!(e3));

    if(s.check()==unsat){
        return true;
    }
    else {
        return false;
    }

}
z3::expr Converter::createExpr(std::string e){
    if(e[0] == 'R'){
        return c.int_const(e.c_str());
    }
    else if(e[0] == '0'){
        std::stringstream s1,s2;
        int i;
        s1<<e;
        s1>>std::hex>>i;
        s2<<i;
        return c.int_val(s2.str().c_str());
    }
    else {
        std::cout<<"Shit"<<std::endl;
        return c.int_const("0");
    }
}

void Converter::loadMap(std::vector<ReilInstruction> rInsns1 , std::vector<ReilInstruction> rInsns2){
    
    for(auto i : rInsns1){
        
    }
}