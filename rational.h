#ifndef RATIONAL_H
#define RATIONAL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Rational {
    int num;
    int denom;
};

typedef struct Rational Rational;

/***************************************************
* int read_rational(FILE*, int*, int*, int*, int*, char*)
* reads and interprets the rationals in a file
*
* Parameters:
* FILE*: file
* int*: numerator1
* int*: denominator1
* int*: numerator2
* int*: denominator2
* char*: operation
*
* Returns:
* The amount of pointers in the expression
************************************************/	
int read_rational(FILE*, int*, int*, int*, int*, char*);

/***************************************************
* int create_rational(const int num, const int denom)
* creates a rational
*
* Parameters:
* num: numerator
* denom: denominator
*
* Returns:
* A rational
************************************************/	
Rational create_rational(const int num, const int denom);

/***************************************************
* int copy_rational(const Rational*)
* creates a rational clone
*
* Parameters:
* Rational*: rational
*
* Returns:
* A rational copy of the inputted rational
************************************************/	
Rational copy_rational(const Rational*);

/***************************************************
* int simplify(const Rational*)
* simplifies rational
*
* Parameters:
* Rational*: rational
*
* Returns:
* A simplified version of the inputted rational
************************************************/	
void simplify(Rational*);

/***************************************************
* int gcd (int, int)
* gives the gcd of two denominators
*
* Parameters:
* int: denominator1
* int: denominator2
*
* Returns:
* A rational copy of the inputted rational
************************************************/	
int gcd (int, int);

/***************************************************
* int add(const Rational*, const Rational*)
* adds two rational
*
* Parameters:
* Rational*: rational1
* Rational*: rational2
*
* Returns:
* A rational sum of the two rationals given
************************************************/	
Rational add(const Rational*, const Rational*);

/***************************************************
* int subtract(const Rational*, const Rational*)
* subtracts two rational
*
* Parameters:
* Rational*: rational1
* Rational*: rational2
*
* Returns:
* A rational difference of the two rationals given
************************************************/	
Rational subtract(const Rational*, const Rational*);

/***************************************************
* int multiply(const Rational*, const Rational*)
* multiplies two rational
*
* Parameters:
* Rational*: rational1
* Rational*: rational2
*
* Returns:
* A rational product of the two rationals given
************************************************/	
Rational multiply(const Rational*, const Rational*);

/***************************************************
* int divide(const Rational*, const Rational*)
* divides two rational
*
* Parameters:
* Rational*: rational1
* Rational*: rational2
*
* Returns:
* A rational that is the first rational given divided by the second given
************************************************/	
Rational divide(const Rational*, const Rational*);

/***************************************************
* void print(FILE*, const Rational*)
* prints a rational in the file
*
* Parameters:
* FILE*: file
* Rational*: rational
*
* Returns:
* A rational in the file given
************************************************/	
void print(FILE*, const Rational*);

/***************************************************
* bool equal(const Rational*, const Rational*)
* checks if two rationals are equal
*
* Parameters:
* Rational*: rational1
* Rational*: rational2
*
* Returns:
* A boolean determining whether they are equal or not
************************************************/	
bool equal(const Rational*, const Rational*);

/***************************************************
* int compare(const Rational*, const Rational*)
* compares two rationals
*
* Parameters:
* Rational*: rational1
* Rational*: rational2
*
* Returns:
* An int indicating which one is greater, or if they are equal
************************************************/	
int compare(const Rational*, const Rational*);

#endif