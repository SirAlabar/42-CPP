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
        std::istringstream iss(literal);
        int value;
        iss >> value;
        convertFromInt(value);
    }
    else if (isFloat(literal))
    {
        std::string withoutF = literal.substr(0, literal.length() - 1);
        std::istringstream iss(withoutF);
        float value;
        iss >> value;
        convertFromFloat(value);
    }
    else if (isDouble(literal))
    {
        std::istringstream iss(literal);
        double value;
        iss >> value;
        convertFromDouble(value);
    }
    else
    {
        std::cout << "Error: Invalid literal format." << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0])) ||
           (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && std::isprint(literal[1]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    std::istringstream iss(literal);
    int val;
    char remaining;

    return (iss >> val) && !(iss >> remaining);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.empty())
        return false;

    if (literal[literal.length() - 1] != 'f')
        return false;
    
    std::string withoutF = literal.substr(0, literal.length() - 1);
    std::istringstream iss(withoutF);
    float val;
    char remaining;

    return (iss >> val) && !(iss >> remaining) && (withoutF.find('.') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty())
        return false;

    std::istringstream iss(literal);
    double val;
    char remaining;

    return (iss >> val) && !(iss >> remaining) && (literal.find('.') != std::string::npos);
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return (literal == "nan" || literal == "+inf" || literal == "-inf"||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

void ScalarConverter::convertFromChar(char c)
{
    //char
    std::cout << "char: `" << c << "'" << std::endl;
    //int
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    //float
    std::cout << "float: " << static_cast<float>(c) << "0.f" << std::endl;
    //double
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int n) 
{
    //char
    if (n >= 0 && n <= 127) 
    {
        if (std::isprint(n))
            std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } 
    else 
    {
        std::cout << "char: impossible" << std::endl;
    }
    //int
    std::cout << "int: " << n << std::endl;
    //float
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    //double
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float f) 
{
    //char
    if (f >= 0 && f <= 127 && !std::isnan(f) && !std::isinf(f)) 
    {
        if (std::isprint(static_cast<int>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } 
    else 
    {
        std::cout << "char: impossible" << std::endl;
    }
    
    //int
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || 
        std::isnan(f) || std::isinf(f)) 
    {
        std::cout << "int: impossible" << std::endl;
    } 
    else 
    {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    
    //float
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    
    //double
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(double d)
{
    //char
    if (d >= 0 && d <= 127 && !std::isnan(d) && !std::isinf(d)) 
    {
        if (std::isprint(static_cast<int>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else 
    {
        std::cout << "char: impossible" << std::endl;
    }
    
    //int
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || 
        std::isnan(d) || std::isinf(d)) 
    {
        std::cout << "int: impossible" << std::endl;
    } 
    else 
    {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }

    //float
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    }

    //double
    std::cout << "double: " << d << std::endl;

}

void ScalarConverter::convertFromPseudoLiteral(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;

    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}