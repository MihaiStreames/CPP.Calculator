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

enum Op { None, AddOp, Sub, Mult, Div, SquareRootOp, PercentOp };

class Calc {
public:
    Calc();
    Op currentOperation;

    void operation(const string& input);
    void clear();
    void plusMinus();
    void Percent();

    void setNewOperandExpected();
    void updateNumber(double value);
    Op getCurrentOperation() const;
    void setCurrentOperation(const string& opStr);
    double getStackValue(int index);
    void setStackValue(int index, double value);
    void setNumber(double value);
    double getNumber() const;
    void setError(bool value);
    bool getError() const;

private:
    bool error;
    double Number;
    double stack[2];

    static const unordered_map<string, function<void(Calc&)>> operations;
};

#endif // CALC_H