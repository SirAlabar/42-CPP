#pragma once

#include <string>
#include <stack>

class RPN 
{
private:
    std::stack<int> _stack;

    void processToken(const std::string& token);
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    int performOperation(int a, int b, const std::string& op) const;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int calculate(const std::string& expression);
};