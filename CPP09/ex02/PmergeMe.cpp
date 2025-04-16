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

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobNumbers;
    jacobNumbers.push_back(0);
    jacobNumbers.push_back(1);
    
    size_t i = 2;
    while (true)
    {
        size_t next = jacobNumbers[i-1] + 2 * jacobNumbers[i-2];
        if (next >= n)
            break;
        jacobNumbers.push_back(next);
        i++;
    }
    
    return jacobNumbers;
}


std::vector<size_t> PmergeMe::generateInsertionOrder(size_t n)
{
    std::vector<size_t> result;
    
    if (n <= 1)
    {
        if (n == 1)
            result.push_back(0);
        return result;
    }
    
    std::vector<size_t> jacobNumbers = generateJacobsthalSequence(n);
    
    result.push_back(0);
    
    for (size_t i = 2; i < jacobNumbers.size(); ++i)
    {
        for (size_t j = jacobNumbers[i]; j > jacobNumbers[i-1]; --j)
        {
            if (j-1 < n)
                result.push_back(j-1);
        }
    }
    std::vector<bool> used(n, false);
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i] < n)
            used[result[i]] = true;
    }
    for (size_t i = 1; i < n; ++i)
    {
        if (!used[i])
            result.push_back(i);
    }
    
    return result;
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
        return;
    }
    if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            std::swap(arr[0], arr[1]);
        }
        return;
    }
    
    bool hasOdd = (size % 2 != 0);
    int oddValue = 0;
    if (hasOdd)
    {
        oddValue = arr[size - 1];
    }
    
    // Step 1: Form pairs and ensure smaller element is in first position
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < size - (hasOdd ? 1 : 0); i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];
        if (a <= b)
        {
            pairs.push_back(std::make_pair(a, b));
        }
        else
        {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    // Step 2: Extract larger elements for recursive sorting
    std::vector<int> largerElements;
    std::vector<int> smallElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
        smallElements.push_back(pairs[i].first);
    }
    
    // Step 3: Recursively sort larger elements
    fordJohnsonSortVector(largerElements);
    
    // Step 4: Build the main chain
    std::vector<int> mainChain;
    size_t firstPairIndex = 0;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second == largerElements[0])
        {
            firstPairIndex = i;
            break;
        }
    }
    
    mainChain.push_back(smallElements[firstPairIndex]);
    mainChain.push_back(largerElements[0]);
    
    // Step 5: Keep track of which smaller elements have been processed
    std::vector<bool> smallUsed(smallElements.size(), false);
    smallUsed[firstPairIndex] = true;
    
    // Step 6: Collect remaining smaller elements for later insertion
    std::vector<int> remainingSmall;
    std::vector<size_t> originalIndices;
    for (size_t i = 0; i < smallElements.size(); ++i)
    {
        if (i != firstPairIndex)
        {
            remainingSmall.push_back(smallElements[i]);
            originalIndices.push_back(i);
        }
    }
    
    // Step 7: Add the rest of the sorted larger elements
    for (size_t i = 1; i < largerElements.size(); ++i)
    {
        mainChain.push_back(largerElements[i]);
    }
    
    // Step 8: Generate insertion order using the Jacobsthal sequence
    std::vector<size_t> insertOrder = generateInsertionOrder(remainingSmall.size());

    // Step 9: Insert smaller elements using binary insertion in Jacobsthal order
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];
        if (index < remainingSmall.size())
        {
            int valueToInsert = remainingSmall[index];
            binaryInsertVector(mainChain, valueToInsert, 0, mainChain.size());
        }
    }
    // Step 10: Insert the odd element, if it exists
    if (hasOdd)
    {
        binaryInsertVector(mainChain, oddValue, 0, mainChain.size());
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
        return;
    }
    if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            std::swap(arr[0], arr[1]);
        }
        return;
    }
    
    bool hasOdd = (size % 2 != 0);
    int oddValue = 0;
    if (hasOdd)
    {
        oddValue = arr[size - 1];
    }
    
    // Step 1: Form pairs and ensure smaller element is in first position
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < size - (hasOdd ? 1 : 0); i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];
        if (a <= b)
        {
            pairs.push_back(std::make_pair(a, b));
        }
        else
        {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    // Step 2: Extract larger elements for recursive sorting
    std::deque<int> largerElements;
    std::deque<int> smallElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
        smallElements.push_back(pairs[i].first);
    }
    
    // Step 3: Recursively sort larger elements
    fordJohnsonSortDeque(largerElements);
    
    // Step 4: Build the main chain
    std::deque<int> mainChain;
    size_t firstPairIndex = 0;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second == largerElements[0])
        {
            firstPairIndex = i;
            break;
        }
    }
    
    mainChain.push_back(smallElements[firstPairIndex]);
    mainChain.push_back(largerElements[0]);
    
    // Step 5: Keep track of which smaller elements have been processed
    std::vector<bool> smallUsed(smallElements.size(), false);
    smallUsed[firstPairIndex] = true; // Mark the first one as used
    
    // Step 6: Collect remaining smaller elements for later insertion
    std::deque<int> remainingSmall;
    std::vector<size_t> originalIndices;
    for (size_t i = 0; i < smallElements.size(); ++i)
    {
        if (i != firstPairIndex)
        {
            remainingSmall.push_back(smallElements[i]);
            originalIndices.push_back(i);
        }
    }
    
    // Step 7: Add the rest of the sorted larger elements
    for (size_t i = 1; i < largerElements.size(); ++i)
    {
        mainChain.push_back(largerElements[i]);
    }
    
    // Step 8: Generate insertion order using the Jacobsthal sequence
    std::vector<size_t> insertOrder = generateInsertionOrder(remainingSmall.size());
    
    // Step 9: Insert smaller elements using binary insertion in Jacobsthal order
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];
        if (index < remainingSmall.size())
        {
            int valueToInsert = remainingSmall[index];
            binaryInsertDeque(mainChain, valueToInsert, 0, mainChain.size());
        }
    }
    // Step 10: Insert the odd element, if it exists
    if (hasOdd)
    {
        binaryInsertDeque(mainChain, oddValue, 0, mainChain.size());
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

// void PmergeMe::validateSorting() const
// {
//     if (_vector.size() != _original.size() || _deque.size() != _original.size()) {
//         std::cerr << "ERROR: Size mismatch after sorting!" << std::endl;
//         std::cerr << "Original: " << _original.size() << ", Vector: " << _vector.size() 
//                   << ", Deque: " << _deque.size() << std::endl;
//     }
    
//     Verify vector is sorted
//     for (size_t i = 1; i < _vector.size(); i++) {
//         if (_vector[i-1] > _vector[i]) {
//             std::cerr << "ERROR: Vector not properly sorted at position " << i << std::endl;
//         }
//     }
    
//     Verify deque is sorted
//     for (size_t i = 1; i < _deque.size(); i++) {
//         if (_deque[i-1] > _deque[i]) {
//             std::cerr << "ERROR: Deque not properly sorted at position " << i << std::endl;
//         }
//     }
// }
