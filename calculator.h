#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <functional>

using namespace std;

enum Op { None, AddOp, Subtract, Multiply, Divide, SquareRootOp, PercentOp };

class Calc {
public:
    Calc();
    void Operation(const string& input);
    void Clear();
    void Sqrt();
    void PerformOperation();
    void PlusMinus();
    void Percent();
    void Add();
    void Sub();
    void Mult();
    void Div();
    double SquareRoot(double n);

    void SetNewOperandExpected();
    void UpdateNumber(double value);

    double getNumber() const { return Number; }
    bool isError() const { return error; }

private:
    double Number;
    double stack[2];

    Op currentOperation;
    bool error;
    void SetCurrentOperation(Op op);
    static const unordered_map<string, function<void(Calc&)>> operations;
};

#endif // CALC_H