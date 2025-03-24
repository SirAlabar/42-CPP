# 🏫 C++ Modules Project README

## Overview 🌟

This repository contains my implementations of the C++ modules from the curriculum. These modules are designed to introduce Object-Oriented Programming concepts using C++ as the language of choice.

## Project Structure 📂

The repository is organized by modules (CPP00 through CPP09), with each module containing multiple exercises:

```
└── CPP Modules
    ├── CPP00
    │   ├── ex00 - Megaphone
    │   ├── ex01 - PhoneBook
    │   └── ex02 - Account
    ├── CPP01
    │   ├── ex00 - Zombie
    │   ├── ex01 - ZombieHorde
    │   ├── ex02 - Brain
    │   ├── ex03 - Weapon
    │   ├── ex04 - File replacement
    │   ├── ex05 - Harl
    │   └── ex06 - HarlFilter
    ├── CPP02
    │   ├── ex00 - Fixed point number class
    │   ├── ex01 - More useful fixed point
    │   ├── ex02 - Operators overload
    │   └── ex03 - BSP
    ├── CPP03
    │   ├── ex00 - ClapTrap
    │   ├── ex01 - ScavTrap
    │   ├── ex02 - FragTrap
    │   └── ex03 - DiamondTrap
    ├── CPP04
    │   ├── ex00 - Polymorphism
    │   ├── ex01 - Brain
    │   ├── ex02 - Abstract class
    │   └── ex03 - Interface & recap
    ├── CPP05
    │   ├── ex00 - Bureaucrat
    │   ├── ex01 - Form
    │   ├── ex02 - Concrete forms
    │   └── ex03 - Intern
    ├── CPP06
    │   ├── ex00 - Scalar conversion
    │   ├── ex01 - Serialization
    │   └── ex02 - Type identification
    ├── CPP07
    │   ├── ex00 - Template functions
    │   ├── ex01 - Iter
    │   └── ex02 - Array
    ├── CPP08
    │   ├── ex00 - EasyFind
    │   ├── ex01 - Span
    │   └── ex02 - MutantStack
    └── CPP09
        ├── ex00 - Bitcoin Exchange
        ├── ex01 - RPN
        └── ex02 - PmergeMe
```

## Compilation 🛠️

All exercises are compiled with:
```bash
c++ -Wall -Wextra -Werror [-std=c++98] *.cpp -o <executable_name>
```

Each module has a Makefile with the following rules:
- `make` or `make all`: Compiles the program
- `make clean`: Removes object files
- `make fclean`: Removes object files and executable
- `make re`: Executes `fclean` and `all` rules

## Module Descriptions 📚

### CPP00: Introduction to C++ 🎯
- **ex00**: Megaphone 📢 - Convert input to uppercase
- **ex01**: PhoneBook 📱 - Simple contact manager
- **ex02**: Account 💼 - Recreate a class implementation from logs

### CPP01: Memory allocation and pointers 🧟
- **ex00-01**: Zombie 🧠 - Memory management with stack/heap allocation
- **ex02**: Brain 🧠 - Pointers vs References
- **ex03**: Unnecessary violence ⚔️ - Using references and pointers appropriately
- **ex04**: Sed is for losers 📄 - File manipulation in C++
- **ex05-06**: Harl 🗣️ - Using pointers to member functions

### CPP02: Operator overloading and Orthodox Canonical Form 🔢
- **ex00-02**: Fixed Point Numbers 🔢 - Implementation with operator overloading
- **ex03**: Binary Space Partitioning (BSP) 📐 - Point in triangle algorithm

### CPP03: Inheritance 🤖
- **ex00-03**: ClapTrap Family 🤖 - Exploration of inheritance

### CPP04: Polymorphism and abstract classes 🐕
- **ex00-02**: Animal Kingdom 🐕🐈 - Polymorphism and abstract classes
- **ex03**: Materia System ✨ - Interface implementation with AMateria and Character classes

### CPP05: Exceptions 📝
- **ex00-03**: Bureaucracy 📋 - Exception handling in an office environment

### CPP06: C++ casts 🔄
- **ex00**: Scalar Conversion 🔄 - Type conversion between scalar types
- **ex01**: Serialization 💾 - Data conversion using reinterpret_cast
- **ex02**: Runtime type identification

### CPP07: Templates 📋
- **ex00**: Basic function templates (swap, min, max)
- **ex01**: Function template with array iteration
- **ex02**: Template class implementation (Array)

### CPP08: STL Containers 🧰
- **ex00**: Algorithm to find elements in containers
- **ex01**: Span class for storing numbers and finding spans
- **ex02**: MutantStack implementation extending std::stack

### CPP09: STL Containers II 💰
- **ex00**: Bitcoin price lookup program using STL containers
- **ex01**: Reverse Polish Notation calculator
- **ex02**: PmergeMe - Implementation of merge-insert sort algorithm

## Notes 📌

- All code complies with the C++98 standard
- Memory leaks are handled appropriately in all exercises
- Classes are designed in Orthodox Canonical Form (when required)
- Include guards are used to prevent multiple inclusions
- Using namespace and friend keywords are avoided (unless explicitly required)

## Testing ✅

Each exercise includes tests to demonstrate the functionality and correctness of the implementation. Run the executables to see the results of these tests.
