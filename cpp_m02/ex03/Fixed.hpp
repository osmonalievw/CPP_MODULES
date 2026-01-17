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

    // Operator Overloads
    Fixed &operator=(const Fixed &other);

    // Comparison Operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment / Decrement
    Fixed &operator++(void); // Prefix
    Fixed operator++(int);   // Postfix
    Fixed &operator--(void); // Prefix
    Fixed operator--(int);   // Postfix

    // Static Functions (Min / Max)
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Getters / Setters / Converters
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

// Stream Operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif