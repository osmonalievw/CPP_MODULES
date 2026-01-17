#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
  private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

  public:
    // Constructors & Destructor
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(const int n);
    Fixed(const float n);
    ~Fixed(void);

    // Operators
    Fixed &operator=(const Fixed &other);

    // Getters & Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Stream operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif