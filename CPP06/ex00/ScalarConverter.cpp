#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cout << "Error: Empty string provided." << std::endl;
        return ;
    }

    if (isPseudoLiteral(literal))
    {
        convertFromPseudoLiteral(literal);
    }
    else if (isChar(literal))
    {
        convertFromChar(literal[0]);
    }
    else if (isInt(literal))
    {
        convertFromInt(std::atoi(literal.c_str()));
    }
    else if (isFloat(literal))
    {
        convertFromFloat(std::atof(literal.c_str()));
    }
    else if (isDouble(literal))
    {
        convertFromDouble(std::atof(literal.c_str()));
    }
    else
    {
        std::cout << "Error: Invalid literal format." << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal);
bool ScalarConverter::isInt(const std::string& literal);
bool ScalarConverter::isFloat(const std::string& literal);
bool ScalarConverter::isDouble(const std::string& literal);
bool ScalarConverter::isPseudoLiteral(const std::string& literal);

void ScalarConverter::convertFromChar(char c);
void ScalarConverter::convertFromInt(int n);
void ScalarConverter::convertFromFloat(float f);
void ScalarConverter::convertFromDouble(double d);
void ScalarConverter::convertFromPseudoLiteral(const std::string& literal);