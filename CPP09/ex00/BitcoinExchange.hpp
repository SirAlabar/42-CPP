#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> database;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(float value) const;
    std::string findClosestDate(const std::string& date) const;
    bool parseLine(const std::string& line, std::string& date, float& value) const;
    bool parseDbLine(const std::string& line, std::string& date, float& rate) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
};