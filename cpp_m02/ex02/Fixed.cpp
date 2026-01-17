#include "Fixed.hpp"

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTOR                                                  */
/* ========================================================================== */

Fixed::Fixed(void) : _fixedPointValue(0) {}
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {}
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}
Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {}
Fixed::~Fixed(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

/* -------------------------- Comparison Operators -------------------------- */

bool Fixed::operator>(const Fixed& other) const { return this->_fixedPointValue > other._fixedPointValue; }

bool Fixed::operator<(const Fixed& other) const { return this->_fixedPointValue < other._fixedPointValue; }

bool Fixed::operator!=(const Fixed& other) const { return this->_fixedPointValue != other._fixedPointValue; }

bool Fixed::operator==(const Fixed& other) const { return this->_fixedPointValue == other._fixedPointValue; }

bool Fixed::operator>=(const Fixed& other) const { return this->_fixedPointValue >= other._fixedPointValue; }

bool Fixed::operator<=(const Fixed& other) const { return this->_fixedPointValue <= other._fixedPointValue; }

/* -------------------------- Arithmetic Operators -------------------------- */

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    long long n = (long long)this->_fixedPointValue * (long long)other._fixedPointValue;
    res.setRawBits((int)(n >> _fractionalBits));
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed res;
    long long n = (long long)this->_fixedPointValue << _fractionalBits;

    if (other._fixedPointValue != 0) res.setRawBits((int)(n / other._fixedPointValue));

    return res;
}

/* ----------------------- Increment / Decrement ---------------------------- */

Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_fixedPointValue--;
    return tmp;
}

/* ========================================================================== */
/* STATIC MEMBER FUNCTIONS                                                    */
/* ========================================================================== */

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

/* ========================================================================== */
/* GETTERS / SETTERS                                                          */
/* ========================================================================== */

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (float)(1 << _fractionalBits); }

int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

/* ========================================================================== */
/* GLOBAL OPERATORS                                                           */
/* ========================================================================== */

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}