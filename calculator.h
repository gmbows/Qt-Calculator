#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>

#include <QLCDNumber>

enum C_OP {
    OP_ADD,
    OP_MULT,
    OP_DIV,
    OP_SUB,
};

class Calculator
{
public:
    Calculator();

    QLCDNumber *display;
    void update_display();

    long long int displayValue = 0;
    long long int lastValue = 0;

    void add_digit(int);

    C_OP op;
    unsigned int power = 0;

    int getLastDigit();

    void set_op(C_OP);
    void equals();
    void del();
    void clear();
};

#endif // CALCULATOR_H
