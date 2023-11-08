#ifndef CALC_H
#define CALC_H

#include <string>
#include <cassert>
#include <cctype>
#include <stdexcept>
#include <iostream>

using namespace std;

enum OperationType {
    None, AddOp, Subtract, Multiply, Divide, SquareRootOp, PercentOp
};

class Calc {
public:
    Calc();
    double Number;

    void Operation(const std::string& n);
    void PlusMinus();
    void Percent();
    bool isError() const { return error; }
    void Clear();

private:
    double stack[2];
    OperationType currentOperation;

    bool error; // Error flag
    void PerformOperation();
    void Add();
    void Sub();
    void Mult();
    void Div();
    void Sqrt();
    double SquareRoot(double n);
};

#endif // CALC_H