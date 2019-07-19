
#include<z3++.h>
#include<vector>
#include<set>
#include<string>
#include<tuple>
#include<functional>
#include<map>
#include<utility>
#include<sstream>

#include"converter.h"

using namespace z3;
Converter::Converter(){}
Converter::~Converter(){}

bool Converter::checkEqualityOfAdd(std::vector<ReilInstruction> reilAddInsns1, std::vector<ReilInstruction> reilAddInsns2){
    //for(auto i : reilAddInsns1) std::cout<<"i: "<<i;
    //for(auto i : reilAddInsns1) for(auto j : i.operands) std::cout<<j<<std::endl;
    context c;
    std::set<std::string> regs;
    std::set<std::string> regs2;
    std::map<std::string, expr> regExps;
    std::map<std::string, expr> regExps2;
    for(auto i : reilAddInsns1){
        if(regs.find(i.operands[0].name.c_str()) == regs.end()){
            //std::cout<<i.operands[0].name<<std::endl;
            regs.emplace(i.operands[0].name.c_str());
        }
    }
    for(auto i : reilAddInsns2){
        if(regs.find(i.operands[0].name.c_str()) == regs.end()){
            //std::cout<<i.operands[0].name<<std::endl;
            std::cout<<"Result is unsat because registers differ"<<std::endl;
            return false;
        }
        else {
            regs2.emplace(i.operands[0].name.c_str());
        }
    }
    //for(auto i: regs) std::cout<<"i: "<<i<<std::endl;
    for(auto i : regs){
        expr r = c.int_const(i.c_str());
        regExps.emplace(i, r);
    }
    
    for(auto i : regs2){
        expr r = c.int_const(i.c_str());
        regExps2.emplace(i, r);
    }
    //for(auto i : regExps) std::cout<<"i: "<<i.second <<std::endl;
    //std::cout<<regExps.find("R_R12")->second<<std::endl;
    for(auto i : reilAddInsns1){
        expr e1 = c.int_val("1"), e2 = c.int_val("2");
        auto it = regExps.find(i.operands[0].name);
        auto it1 = regExps.find(i.operands[1].name);
        auto it2 = regExps.find(i.operands[2].name);
        if(it1 == regExps.end()){
            e1 = this->createExpr(i.operands[1].name, c);
        }
        else {
            e1 = it1->second;
        }
        if(it2 == regExps.end()){
            e2 = this->createExpr(i.operands[2].name, c);
        }
        else{
            e2 = it2->second;
        }
        /*
        std::cout<<"-----------------"<<std::endl;
        std::cout<<"First Arg "<<std::endl;
        std::cout<<"E1 : "<<e1<<std::endl;
        std::cout<<"E2 : "<<e2<<std::endl;
        std::cout<<"RES before : "<<it->second<<std::endl;
        /* */
        it->second =  e1 + e2;
        /*
        std::cout<<"RES after : "<<it->second<<std::endl;
        std::cout<<"-----------------"<<std::endl;
        /* */
    }
    
    //for(auto i : regExps) std::cout<<i.second<<std::endl;
    
    for(auto i : reilAddInsns2){
        expr e1 = c.int_val("1"), e2 = c.int_val("2");
        auto it = regExps2.find(i.operands[0].name);
        auto it1 = regExps2.find(i.operands[1].name);
        auto it2 = regExps2.find(i.operands[2].name);
        if(it1 == regExps2.end()){
            e1 = this->createExpr(i.operands[1].name, c);
        }
        else {
            e1 = it1->second;
        }
        if(it2 == regExps2.end()){

            e2 = this->createExpr(i.operands[2].name, c);
        }
        else{
            e2 = it2->second;
        }
        /*
        std::cout<<"-----------------"<<std::endl;
        std::cout<<"Second Arg "<<std::endl;
        std::cout<<"E1 : "<<e1<<std::endl;
        std::cout<<"E2 : "<<e2<<std::endl;
        std::cout<<"RES before : "<<it->second<<std::endl;
        /* */
        it->second =  e1 + e2;
        /* 
        std::cout<<"RES after : "<<it->second<<std::endl;
        std::cout<<"-----------------"<<std::endl;
        /* */
    }
    solver s(c);
    for(auto i : regs2){
        //std::cout<<"i from regs2 : "<<i<<std::endl;
        auto it1 = regExps.find(i);
        auto it2 = regExps2.find(i);
        if(it1 == regExps.end()){
            std::cout<<"Result is unsat because registers differ"<<std::endl;
            return false;
        }
    }
    for(auto i : regs){
        //std::cout<<"i from regs1 : "<<i<<std::endl;
        auto it1 = regExps.find(i);
        auto it2 = regExps2.find(i);
        solver s1(c);
        s = s1;
        if(it2 == regExps2.end()){
            std::cout<<"Result is unsat because registers differ"<<std::endl;
            return false;
        }
        it1->second = it1->second.simplify();
        it2->second = it2->second.simplify();
        /* */
        std::cout<<"-----------------"<<std::endl;
        std::cout<<"--- Solver"<<std::endl;
        std::cout<<"--- it1 : "<<it1->second<<std::endl;
        std::cout<<"--- it2 : "<<it2->second<<std::endl;
        std::cout<<"-----------------"<<std::endl;
        /* */
        s.add(!(it1->second == it2->second));
        if(s.check() == sat){
            std::cout<<"unsat"<<std::endl;
            return false;
        }

    }
    //std::cout<<s.assertions()<<std::endl;
    if(s.check() == unsat){
        std::cout<<"sat"<<std::endl;
        return true;
    }
    else{
        std::cout<<"unsat"<<std::endl;
        return false;
    }
}


expr Converter::createExpr(std::string expression, context &c){
    if(expression[0] == 'R'){
        expr e = c.int_const(expression.c_str());
        return e;
    }
    else if(expression[0] == '0'){
        std::stringstream s1,s2;
        int i;
        s1<<expression;
        s1>>std::hex>>i;
        s2<<i;
        expr e = c.int_val(s2.str().c_str());
        return e;
    }
    else{
        std::cout<<"WTF"<<std::endl;
        return expr(c.int_val("0"));
    }
}