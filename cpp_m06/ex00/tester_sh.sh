#!/bin/sh

PROG=${1:-./convert}   # default ./convert, or pass path as first arg

tests="
0
7
42
-42
a
Z
*
nan
nanf
+inf
-inf
+inff
-inff
42.0
42.0f
4.2
4.2f
hello
12abc
"

for t in $tests; do
    echo "==============================="
    echo "$PROG \"$t\""
    $PROG "$t"
    echo
done

