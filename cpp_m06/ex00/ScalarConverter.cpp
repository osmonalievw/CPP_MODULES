#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void)other;
    return;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void)other;
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

static void printChar(double base)
{
    std::cout << "char: ";
    if (base < 0 || base > 127)
        std::cout << "impossible\n";
    else if (base < 32 || base > 126)
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(base) << "'" << std::endl;
}

static void printInt(double base)
{
    std::cout << "int: ";
    if (base < INT_MIN || base > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(base) << std::endl;
}

static void printFloat(double base)
{
    float f = static_cast<float>(base);

    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double base)
{
    double d = base;

    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

static bool isPseudoLiteral(const std::string &s)
{
    return (s == "-inff" || s == "+inff" || s == "nanf" ||
            s == "-inf" || s == "+inf" || s == "nan");
}

static void printPseudoLiteral(const std::string &s)
{

    std::cout << "char: impossible\n"
              << "int: impossible\n";
    if (s == "-inff" || s == "+inff" || s == "nanf")
    {
        std::cout << "float: " << s << std::endl;
        std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
    }
    else
        std::cout << "float: " << s << "f\n"
                  << "double: " << s << std::endl;
}

void ScalarConverter::convert(const std::string &val)
{
    if (isPseudoLiteral(val))
    {
        printPseudoLiteral(val);
        return;
    }
    // 1) single non-digit char
    if (val.length() == 1 && !std::isdigit(val[0]))
    {
        double base = static_cast<double>(val[0]);
        printChar(base);
        printInt(base);
        printFloat(base);
        printDouble(base);
        return;
    }
    // 2) numeric starting with digit
    if (!val.empty() && (std::isdigit(val[0]) || val[0] == '+' || val[0] == '-'))
    {
        char *endptr = 0;
        long l_val = 0;
        double d_val = 0.0;
        bool is_decimal = (val.find('.') != std::string::npos);

        if (is_decimal)
            d_val = std::strtod(val.c_str(), &endptr);
        else
            l_val = std::strtol(val.c_str(), &endptr, 10);

        if (*endptr == '\0' || (is_decimal && *endptr == 'f' && *(endptr + 1) == '\0'))
        {
            double base = is_decimal ? d_val : static_cast<double>(l_val);
            printChar(base);
            printInt(base);
            printFloat(base);
            printDouble(base);
            return;
        }
        else
        {
            std::cout << "Invalid literal\n";
            return;
        }
    }

    // 3) anything else
    std::cout << "Invalid literal\n";
}
