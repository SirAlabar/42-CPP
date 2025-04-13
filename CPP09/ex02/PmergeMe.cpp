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
std::vector<size_t> PmergeMe::generateJacobsthalVector(size_t n)
{
    std::vector<size_t> result;
    if (n == 0)
    {
        return result;
    }

    std::vector<size_t> jbsthal;
    jbsthal.push_back(0);
    jbsthal.push_bach(1);

    while (jbsthal.back() < n)
    {
        size_t next = jbsthal[jbsthal.size() - 1] + 2 * jbsthal[jbsthal.size() - 2];
        jbsthal.push_back(next);
    }

    std::vector<size_t> index;
    for (size_t i = 2; i < jbsthal.size(); i++)
    {
        index.push_back(jbsthal[i]);
        for (size_t j = jbsthal[i] - 1; j > jbsthal[i - 1]; j--)
        {
            if (j <= n)
            {
                index.push_back(j);
            }
        }
    }
    return (index);
}
void PmergeMe::binaryInsertVector(std::vector<int>& arr, int value, size_t start, size_t end)
{
    size_t left = start;
    size_t right = end;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] <= value)
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
            return ;
        }
    }

    //step 1 group pairs
    std::vector<std::pair<int, int> > pairs;
    bool odd = (size % 2 != 0);
    int straggler = 0;

    for (size_t i = 0; i < size - (odd ? 1 : 0); i +=2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
        }
        else
        {
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        }
    }
    if (odd)
    {
        straggler = arr[size - 1];
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

    for (size_t  = 0; i < bigNums.size(); i++)
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

    for (size_t i = 0; i < insertOrder.size() && i < smallNums.size(); i++)
    {
        size_t index = insertOrder[i];
        if (index < smallNums.size())
        {
            int num = smallNums[index];
            binaryInsertVector(mainChain, num, 0, mainChan.size());
        }
    }
    if (odd)
    {
        binaryInsertVector(mainChain, straggler, 0, mainChain.size());
    }

    arr = mainChain;
}

//deque
void PmergeMe::binaryInsertDeque(std::deque<int>& arr, int value, size_t start, size_t end)
{
    size_t left = start;
    size_t right = end;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] <= value)
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
    std::deque<std::pair<int , int> > pairs;
    bool odd = (size % 2 != 0);
    int straggler = 0;

    for (size_t i = 0; i < size - (odd ? 1 : 0); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
        }
        else
        {
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        }
    }
    if (odd)
    {
        straggler = arr[size - 1];
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

    for (size_t  = 0; i < bigNums.size(); i++)
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

    for (size_t i = 0; i < insertOrder.size() && i < smallNums.size(); i++)
    {
        size_t index = insertOrder[i];
        if (index < smallNums.size())
        {
            int num = smallNums[index];
            binaryInsertDeque(mainChain, num, 0, mainChan.size());
        }
    }
    if (odd)
    {
        binaryInsertDeque(mainChain, straggler, 0, mainChain.size());
    }

    arr = mainChain;
}


void PmergeMe::sortWithVector()
{
    clock_t start = clock();
    fordJohnsonSortVector(_vector);
    clock_t end = clock();
    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::sorteWithDeque()
{
    clock_t start = clock();
    fordJohnsonSortDeque(_deque);
    clock_t end = clock();
    _dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

std::string PmergeMe::formatTime(double time) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(5) << time;
    return ss.str();
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _original.size() && i < 10, i++)
    {
        std::cout << _original[i] << " ";
    }
    if (_original.size() > 10)
    {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size() && i < 10; i++)
    {
        std::cout << _vector[i] << " ";
    }
    if (_vector.size() > 10)
    {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimes() const
{
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " <<
    formatTime(_vectorTime) << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " <<
    formatTime(_dequeTime) << " us" << std::endl;
}
