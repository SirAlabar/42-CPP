#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;
    
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        unsigned int distance = std::distance(begin, end);
        if (_numbers.size() + distance > _maxSize)
        {
            throw std::out_of_range("Cannot add range: would exceed capacity");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int getMaxSize() const;
    unsigned int getSize() const;
};