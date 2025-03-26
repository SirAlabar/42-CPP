
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{

}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits)
{

}

Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits)))
{

}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
    {
        this->_rawBits = rhs.getRawBits();
    }
    return (*this);    
}

Fixed::~Fixed(void)
{
    
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_rawBits < rhs.getRawBits());
}   

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_rawBits != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->_rawBits + rhs.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->_rawBits - rhs.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed result;
    long long int temp = (long long int)this->_rawBits * (long long int)rhs.getRawBits();
    result.setRawBits((int)temp >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    long long int temp = ((long long int)this->_rawBits << _fractionalBits) / rhs.getRawBits();
    result.setRawBits((int)temp);
    return (result);    
}

Fixed &Fixed::operator++()
{
    this->_rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed &Fixed::operator--()
{
    this->_rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return (temp);
}

int Fixed::getRawBits(void) const
{
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
