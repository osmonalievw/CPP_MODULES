#include "Fixed.hpp"

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTOR                                                  */
/* ========================================================================== */

Fixed::Fixed(void) : _fixedPointValue(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

/* ========================================================================== */
/* GETTERS / SETTERS                                                          */
/* ========================================================================== */

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

/* ========================================================================== */
/* CONVERSION FUNCTIONS                                                       */
/* ========================================================================== */

float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (float)(1 << _fractionalBits); }

int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

/* ========================================================================== */
/* GLOBAL OPERATORS                                                           */
/* ========================================================================== */

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}