#include "calculator.h"

const unordered_map<string, function<void(Calc&)>> Calc::operations = {
        {"Sqrt", &Calc::Sqrt},
        {"Clear", &Calc::Clear},
        {"+/-", &Calc::PlusMinus},
        {"%", &Calc::Percent},
        {"+", [](Calc& c) { c.SetCurrentOperation(AddOp); }},
        {"-", [](Calc& c) { c.SetCurrentOperation(Subtract); }},
        {"×", [](Calc& c) { c.SetCurrentOperation(Multiply); }},
        {"÷", [](Calc& c) { c.SetCurrentOperation(Divide); }},
        {"=", &Calc::PerformOperation}
};

Calc::Calc() : Number(0), currentOperation(None), error(false) {
    stack[0] = 0;
    stack[1] = 0;
}

void Calc::Operation(const string& input) {
    auto it = operations.find(input);
    if (it != operations.end()) {
        it->second(*this);
    } else if (isdigit(input[0]) || input[0] == '.' || (input[0] == '-' && input.size() > 1)) {
        try {
            UpdateNumber(stod(input));
        } catch (const invalid_argument& ia) {
            error = true;
        }
    } else {
        // Handle error or unknown operation
        error = true;
    }
}

void Calc::Sqrt() {
    double valueToSqrt = (currentOperation == None) ? stack[1] : stack[0];
    double sqrtResult = SquareRoot(valueToSqrt);

    if (error) {
        Number = 0;
    } else {
        Number = sqrtResult;
    }

    stack[0] = Number;
    stack[1] = Number;
}

void Calc::Clear() {
    Number = 0;
    stack[0] = 0;
    stack[1] = 0;
    currentOperation = None;
    error = false;
}

void Calc::PerformOperation() {
    if (error || currentOperation == None) {
        cout << "Error or no current operation, returning" << endl;
        return;
    }

    switch (currentOperation) {
        case AddOp: Add(); break;
        case Subtract: Sub(); break;
        case Multiply: Mult(); break;
        case Divide: Div(); break;
        default: break;
    }

    currentOperation = None;
}

void Calc::UpdateNumber(double value) {
    Number = value;
    if (currentOperation == None) {
        stack[1] = value;
    } else {
        stack[0] = value;
    }
}

void Calc::SetCurrentOperation(Op op) {
    if (currentOperation != None) {
        PerformOperation();
    }
    currentOperation = op;
}

void Calc::SetNewOperandExpected() {
    stack[0] = Number;
    Number = 0;
}

void Calc::PlusMinus() {
    if (error || currentOperation != None) return;
    stack[1] = -stack[1];
    Number = stack[1];
}

void Calc::Percent() {
    if (error) return;

    double percentValue = stack[0] / 100.0;

    if (currentOperation == AddOp) {
        Number = stack[1] + (stack[1] * percentValue);
    } else if (currentOperation == Subtract) {
        Number = stack[1] - (stack[1] * percentValue);
    } else {
        Number = stack[1] * percentValue;
    }

    stack[0] = Number;
}

void Calc::Add() {
    Number = stack[1] + stack[0];
    stack[1] = Number;
}

void Calc::Sub() {
    Number = stack[1] - stack[0];
    stack[1] = Number;
}

void Calc::Mult() {
    Number = stack[1] * stack[0];
    stack[1] = Number;
}

void Calc::Div() {
    if (stack[0] == 0) {
        error = true;
        Number = 0;
        return;
    }
    Number = stack[1] / stack[0];
    stack[1] = Number;
}

double Calc::SquareRoot(double n) {
    if (n < 0) {
        error = true;
        return 0; // Can't sqrt a negative number
    }

    double x = n;
    double y = 1;
    double e = 0.000001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}