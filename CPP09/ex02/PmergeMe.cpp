#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>


PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0) {}

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
        _original = other._original;
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

    if (str.length() > 1 && str[0] == '+')
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

size_t PmergeMe::jacobIndexes(size_t n) 
{
    if (n == 0) 
    {
        return 0;
    }
    if (n == 1) 
    {
        return 1;
    }
    
    size_t prev1 = 1;
    size_t prev2 = 0;
    size_t result = 0;
    
    for (size_t i = 2; i <= n; ++i) 
    {
        result = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = result;
    }
    
    return result;
}

std::vector<size_t> PmergeMe::generateJacobsthalVector(size_t n)
{
    std::vector<size_t> result;
    
    if (n <= 0)
    {
        return result;
    }
        

    if (n == 1) 
    {
        result.push_back(0);
        return result;
    }
    
    std::vector<size_t> jacobNums;
    jacobNums.push_back(0);
    jacobNums.push_back(1);
    
    size_t i = 2;
    while (jacobNums.back() < n) 
    {
        jacobNums.push_back(jacobNums[i-1] + 2 * jacobNums[i-2]);
        i++;
    }
    
    std::vector<size_t> insertIndices;

    if (1 < n) insertIndices.push_back(1);
    

    for (size_t j = 3; j < jacobNums.size() && jacobNums[j-1] <= n; j++) 
    {
        for (size_t k = jacobNums[j-1]; k > jacobNums[j-2]; k--) 
        {
            if (k < n) insertIndices.push_back(k);
        }
    }
    
    size_t lastJ = 0;
    for (size_t j = 0; j < jacobNums.size(); j++) 
    {
        if (jacobNums[j] < n) lastJ = jacobNums[j];
        else break;
    }
    
    for (size_t i = lastJ + 1; i < n; i++) 
    {
        insertIndices.push_back(i);
    }
    
    return insertIndices;
}

//vector
void PmergeMe::binaryInsertVector(std::vector<int>& arr, int value, size_t start, size_t end) 
{
    if (start >= end) 
    {
        arr.insert(arr.begin() + start, value);
        return;
    }
    
    size_t left = start;
    size_t right = end;
    
    while (left < right) 
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid;
        }
    }
    
    arr.insert(arr.begin() + left, value);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
    size_t size = arr.size();

    if (size <= 1)
    {
        return ;
    }
    if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            std::swap(arr[0], arr[1]);
        }
        return ;
    }

    bool hasOdd = (size % 2 != 0);
    int oddNum = 0;
    if (hasOdd)
    {
        oddNum = arr[size - 1];
        size--;
    }

    //step 1 group pairs
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < size; i +=2)
    {
        int a = arr[i];
        int b = arr[i + 1];
        
        if (a > b)
        {
            pairs.push_back(std::make_pair(b, a));
        }
        else
        {
            pairs.push_back(std::make_pair(a, b));
        }
    }

    //step 2 extract larger for each pair
    std::vector<int> bigNums;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        bigNums.push_back(pairs[i].second);
    }

    //step 3 recursive sort big nums
    fordJohnsonSortVector(bigNums);

    //step 4 create main vec with big num sorted
    std::vector<int> mainChain;
    mainChain.push_back(pairs[0].first);

    for (size_t i = 0; i < bigNums.size(); i++)
    {
        mainChain.push_back(bigNums[i]);
    }

    //step 5 insert remain small num using binary insert and jacob sequence
    std::vector<int> smallNums;
    for (size_t i = 1; i < pairs.size(); i++)
    {
        smallNums.push_back(pairs[i].first);
    }

    std::vector<size_t> insertOrder = generateJacobsthalVector(smallNums.size());
    std::cout << "Vetor de Jacobsthal para = " << std::endl;
    for (std::vector<size_t>::const_iterator it = insertOrder.begin();
    it != insertOrder.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];
        if (index < smallNums.size())
        {
            int num = smallNums[index];
            binaryInsertVector(mainChain, num, 0, mainChain.size());
        }
    }
    if (hasOdd)
    {
        binaryInsertVector(mainChain, oddNum, 0, mainChain.size());
    }

    arr = mainChain;
}

//deque
void PmergeMe::binaryInsertDeque(std::deque<int>& arr, int value, size_t start, size_t end)
{  
    if (start >= end) 
    {
        arr.insert(arr.begin() + start, value);
        return;
    }
    
    size_t left = start;
    size_t right = end;
    
    while (left < right) 
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid;
        }
    }
    
    arr.insert(arr.begin() + left, value);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr)
{
    size_t size = arr.size();

    if (size <= 1)
    {
        return ;
    }
    if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            std::swap(arr[0], arr[1]);
            return ;
        }
    }

    //step 1
    bool hasOdd = (size % 2 != 0);
    int oddNum = 0;
    if (hasOdd)
    {
        oddNum = arr[size - 1];
        size--;
    }

    std::deque<std::pair<int , int> > pairs;
    for (size_t i = 0; i < size; i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];
                
        if (a > b)
        {
            pairs.push_back(std::make_pair(b, a));
        }
        else
        {
            pairs.push_back(std::make_pair(a, b));
        }
    }

    //step 2 extract larger for each pair
    std::deque<int> bigNums;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        bigNums.push_back(pairs[i].second);
    }

    //step 3 recursive sort big nums
    fordJohnsonSortDeque(bigNums);

    //step 4 create main vec with big num sorted
    std::deque<int> mainChain;
    mainChain.push_back(pairs[0].first);

    for (size_t i = 0; i < bigNums.size(); i++)
    {
        mainChain.push_back(bigNums[i]);
    }

    //step 5 insert remain small num using binary insert and jacob sequence
    std::deque<int> smallNums;
    for (size_t i = 1; i < pairs.size(); i++)
    {
        smallNums.push_back(pairs[i].first);
    }

    std::vector<size_t> insertOrder = generateJacobsthalVector(smallNums.size());

    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];
        if (index < smallNums.size())
        {
            int num = smallNums[index];
            binaryInsertDeque(mainChain, num, 0, mainChain.size());
        }
    }
    if (hasOdd)
    {
        binaryInsertDeque(mainChain, oddNum, 0, mainChain.size());
    }

    arr = mainChain;
}


void PmergeMe::sortWithVector()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    fordJohnsonSortVector(_vector);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    _vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
}

void PmergeMe::sortWithDeque()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    fordJohnsonSortDeque(_deque);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    _dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
}

std::string PmergeMe::formatTime(double time) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(6) << time;
    return ss.str();
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _original.size() && i < 300; i++)
    {
        std::cout << _original[i] << " ";
    }
    if (_original.size() > 300)
    {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size() && i < 300; i++)
    {
        std::cout << _vector[i] << " ";
    }
    if (_vector.size() > 300)
    {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimes() const
{
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " 
              << formatTime(_vectorTime) << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " 
              << formatTime(_dequeTime) << " us" << std::endl;
}

void PmergeMe::validateSorting() const
{
    if (_vector.size() != _original.size() || _deque.size() != _original.size()) {
        std::cerr << "ERROR: Size mismatch after sorting!" << std::endl;
        std::cerr << "Original: " << _original.size() << ", Vector: " << _vector.size() 
                  << ", Deque: " << _deque.size() << std::endl;
    }
    
    // Verify vector is sorted
    for (size_t i = 1; i < _vector.size(); i++) {
        if (_vector[i-1] > _vector[i]) {
            std::cerr << "ERROR: Vector not properly sorted at position " << i << std::endl;
        }
    }
    
    // Verify deque is sorted
    for (size_t i = 1; i < _deque.size(); i++) {
        if (_deque[i-1] > _deque[i]) {
            std::cerr << "ERROR: Deque not properly sorted at position " << i << std::endl;
        }
    }
}
