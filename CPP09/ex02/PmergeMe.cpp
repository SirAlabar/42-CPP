#include "PmergeMe.hpp"

#define THRESHOLD 16


PmergeMe::PmergeMe() : _vectorTime(0), dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _original = other.original;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidPositiveInt(const std::string& str) const 
{
    std::istringstream iss(str);
    int value;
    char c;

    if (std.length() > 1 && str[0] == '+')
    {
        std::istringstream iss2(str.substr(1));
        if (!(iss2 >> value) || iss2.get(c))
        {
            return (false);
        }
    }
    else if (!(iss >> value) || iss.get(c))
    {
        return (false);
    }
    return (value > 0 && value <= INT_MAX);
}

void PmergeMe::processArgs(int argc, char** argv)
{
    if (argc <= 1)
    {
        throw std::runtime_error("Error: No arguments provided");
    }

    _vector.reserve(argc - 1);
    _original.reserve(argc - 1);
    
    for (int i = 1; i < argc; i++) 
    {
        if (!isValidPositiveInt(argv[i])) 
        {
            throw std::runtime_error("Error");
        }

        std::istringstream iss(argv[i]);
        int value;
        iss >> value;
        
        _vector.push_back(value);
        _deque.push_back(value);
        _original.push_back(value);
    }
}


//vector
void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr);
void PmergeMe::binaryInsertVector(std::vector<int>& arr, int value, size_t start, size_t end);
std::vector<size_t> generateJacobsthalVector(size_t n);


//deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr);
void PmergeMe::binaryInsertDeque(std::deque<int>& arr, int value, size_t start, size_t end);



std::string PmergeMe::formatTime(double time) const;






void PmergeMe::sortWithVector();
void PmergeMe::sorteWithDeque();

void PmergeMe::displayBefore() const;
void PmergeMe::displayAfter() const;
void PmergeMe::displayTimes() const;
