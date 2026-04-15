#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <limits>
#include <cctype>

class ScalarConverter
{
public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static void convert(const std::string &val);
};

#endif
