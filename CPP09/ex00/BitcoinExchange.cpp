#include "BitcoinExchange.hpp"
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database(other.database)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        database = other.database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}


bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return (false);
    }

    std::istringstream iss(date);
    int year, month, day;
    char delim1, delim2;

    if (!(iss >> year >> delim1 >> month >> delim2 >> day) || delim1 != '-' || delim2 != '-')
        return (false);

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return (false);
    }
    else if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeapYear ? 29 : 28))
            return (false);
    }

    return (true);
}

bool BitcoinExchange::isValidValue(float value) const
{
    return (value >= 0 && value <= 1000);
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);

    if (it != database.end() && it->first == date)
    {
        return (date);
    }
    if (it == database.begin() && date < it->first)
    {
        return (it->first);
    }
    if (it == database.end() || it->first > date)
    {
        if (it != database.begin())
        {
            --it;
        }
    }
    return (it->first);
}

bool BitcoinExchange::parseLine(const std::string& line, std::string& date, float& value) const
{
    std::istringstream iss(line);
    std::string dateStr, valueStr;

    if (!std::getline(iss, dateStr, '|'))
        return (false);
    if (!std::getline(iss, valueStr))
        return false;

    dateStr.erase(0, dateStr.find_first_not_of(" \t"));
    dateStr.erase(dateStr.find_last_not_of(" \t") + 1);

    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

    std::istringstream valueStream(valueStr);
    if (!(valueStream >> value))
        return (false);

    date = dateStr;
    return (true);
}

bool BitcoinExchange::parseDbLine(const std::string& line, std::string& date, float& rate) const
{
    std::istringstream iss(line);
    std::string rateStr;

    if (!std::getline(iss, date, ',') || !std::getline(iss, rateStr))
        return (false);
    
    std::istringstream rateStream(rateStr);
    if (!(rateStream >> rate))
        return (false);
    
    return (true);
}


void BitcoinExchange::loadDatabase(const std::string& filename) 
{
    std::ifstream file(filename.c_str());

    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) 
    {
        std::string date;
        float rate;
        
        if (parseDbLine(line, date, rate) && isValidDate(date)) 
        {
            database[date] = rate;
        }
    }
    
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) 
    {
        if (line.find('|') == std::string::npos) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date;
        float value;
        
        if (!parseLine(line, date, value)) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (!isValidDate(date)) 
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (value < 0) 
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) 
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        float exchangeRate = getExchangeRate(date);
        float result = value * exchangeRate;
        
        std::cout << std::fixed << std::setprecision(2);
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    if (database.empty())
    {
        return (0.0f);
    }

    std::string closestDate = findClosestDate(date);
    std::map<std::string, float>::const_iterator it = database.find(closestDate);

    if (it != database.end())
    {
        return (it->second);
    }

    return (0.0f);
}
