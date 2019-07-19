#ifndef OPERATIONS
#define OPERATIONS

#include<vector>
#include<string>

class Operations
{
private:

public:
    std::vector<std::string> allowedOperations = {"ADD"};
    std::string op;
    Operations(std::string operation = "");
    ~Operations();
    bool contains(std::string operation);
    friend std::ostream& operator<<(std::ostream& stream, const Operations& operations);
};

#endif