#include<z3++.h>
#include<iostream>

using namespace z3;
int main(){
    context c;
    solver s(c);
    expr e1 = c.int_const("e1");
    expr e2 = c.int_const("e2");
    expr e3 = c.int_const("e3");
    e3 = !(e1 == e2);
    s.add(e3);

    std::cout<<s.check()<<std::endl;
}