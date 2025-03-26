
#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);

};

#endif