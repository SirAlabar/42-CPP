#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
{

}

RPN::RPN(const RPN& other) : _stack(other._stack)
{

}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }

    return (*this);
}

RPN::~RPN()
{

}

bool RPN::isOperator(const std::string& token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.empty())
    {
        return (false);
    }

    for (size_t i = 0; i < token.length(); i++)
    {
        if (!std::isdigit(token[i]))
        {
            return (false);
        }
    }
    return (true);
}

int RPN::performOperation(int a, int b, const std::string& op) const
{
    if (op == "+")
    {
        return a + b;
    }
    else if (op == "-")
    {
        return a - b;
    }
    else if (op == "*")
    {
        return a * b;
    }
    else if (op == "/")
    {
        if (b == 0)
        {
            throw std::runtime_error("Error: Division by zero");
        }
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}

void RPN::processToken(const std::string& token)
{
    if (isNumber(token))
    {
        std::istringstream iss(token);
        int num;
        iss >> num;
        if (num >= 10)
        {
            throw std::runtime_error("Error: Numbers must be less than 10");
        }
        _stack.push(num);
    }
    else if (isOperator(token))
    {
        if (_stack.size() < 2)
        {
            throw std::runtime_error("Error Not enough operands for operator");
        }

        int b = _stack.top(); _stack.pop();
        int a = _stack.top(); _stack.pop();

        int result = performOperation(a, b, token);
        _stack.push(result);
    }
    else if (!token.empty())
    {
        throw std::runtime_error("Error: Invalid token: " + token);
    }
}

int RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (!_stack.empty())
    {
        _stack.pop();
    }

    while (iss >> token)
    {
        processToken(token);
    }

    if (_stack.size() != 1)
    {
        throw std::runtime_error("Error: Invalid expression (too many values)");
    }

    return _stack.top();
}


