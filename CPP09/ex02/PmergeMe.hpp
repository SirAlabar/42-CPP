#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    std::vector<int> _original;

    double _vectorTime;
    double _dequeTime;

    std::vector<size_t> generateJacobsthalSequence(size_t n);
    std::vector<size_t> generateInsertionOrder(size_t n);

    //vector
    void fordJohnsonSortVector(std::vector<int>& arr);
    void binaryInsertVector(std::vector<int>& arr, int value, size_t start, size_t end);

    //deque
    void fordJohnsonSortDeque(std::deque<int>& arr);
    void binaryInsertDeque(std::deque<int>& arr, int value, size_t start, size_t end);

    std::string formatTime(double time) const;
    bool isValidPositiveInt(const std::string& str) const;

public:

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void processArgs(int argc, char** argv);

    void sortWithVector();
    void sortWithDeque();
    // void validateSorting() const;
    void displayBefore() const;
    void displayAfter() const;
    void displayTimes() const;
};