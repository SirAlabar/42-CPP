#pragam once

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

    //vector
    void fordJohnsonSortVector(std::vector<int>& arr);
    void binaryInsertVector(std::vector<int>& arr, int value, size_t start, size_t end);
    std::vector<size_t> generateJacobsthalVector(size_t n);

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
    void sorteWithDeque();

    void displayBefore() const;
    void displayAfter() const;
    void displayTimes() const;
};