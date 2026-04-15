===============================
./convert "0"
char: Non displayable
int: 0
float: 0.0f
double: 0.0

===============================
./convert "7"
char: Non displayable
int: 7
float: 7.0f
double: 7.0

===============================
./convert "42"
char: '*'
int: 42
float: 42.0f
double: 42.0

===============================
./convert "-42"
char: impossible
int: -42
float: -42.0f
double: -42.0

===============================
./convert "a"
char: 'a'
int: 97
float: 97.0f
double: 97.0

===============================
./convert "Z"
char: 'Z'
int: 90
float: 90.0f
double: 90.0

===============================
./convert "Makefile"
Invalid literal

===============================
./convert "ScalarConverter.cpp"
Invalid literal

===============================
./convert "ScalarConverter.hpp"
Invalid literal

===============================
./convert "ScalarConverter.o"
Invalid literal

===============================
./convert "convert"
Invalid literal

===============================
./convert "main.cpp"
Invalid literal

===============================
./convert "main.o"
Invalid literal

===============================
./convert "output.md"
Invalid literal

===============================
./convert "tester_sh.sh"
Invalid literal

===============================
./convert "nan"
char: impossible
int: impossible
float: nanf
double: nan

===============================
./convert "nanf"
char: impossible
int: impossible
float: nanf
double: nan

===============================
./convert "+inf"
char: impossible
int: impossible
float: +inff
double: +inf

===============================
./convert "-inf"
char: impossible
int: impossible
float: -inff
double: -inf

===============================
./convert "+inff"
char: impossible
int: impossible
float: +inff
double: +inf

===============================
./convert "-inff"
char: impossible
int: impossible
float: -inff
double: -inf

===============================
./convert "42.0"
char: '*'
int: 42
float: 42.0f
double: 42.0

===============================
./convert "42.0f"
char: '*'
int: 42
float: 42.0f
double: 42.0

===============================
./convert "4.2"
char: Non displayable
int: 4
float: 4.2f
double: 4.2

===============================
./convert "4.2f"
char: Non displayable
int: 4
float: 4.2f
double: 4.2

===============================
./convert "hello"
Invalid literal

===============================
./convert "12abc"
Invalid literal

