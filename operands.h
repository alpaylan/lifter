#ifndef OPERANDS
#define OPERANDS

#include<string>
#include<vector>

class Operands{
    private:
        
    public:
        std::vector<std::string> allowedRegisters = {"SP","PC"};
        char type = 'N';//V if Virtual, R if Register, 
        std::string name;
        Operands(std::string name = "None");
        ~Operands();
        bool contains(std::string registerToCheck);
        std::string getValue();
        friend std::ostream& operator<<(std::ostream& stream, const Operands& operand);
};

#endif