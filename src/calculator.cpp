#include "calculator.h"
#include "ops/sqrt.h"
#include "ops/arithmetic.h"

const unordered_map<string, function<void(Calc&)>> Calc::operations = {
        {"Sqrt", &Operations::Sqrt},
        {"clear", &Calc::clear},
        {"+/-", &Calc::plusMinus},
        {"%", &Calc::Percent},
        {"+", &Operations::Add},
        {"-", &Operations::Subtract},
        {"×", &Operations::Multiply},
        {"÷", &Operations::Divide},
        {"=", &Operations::performOperation}
};

Calc::Calc() : Number(0), currentOperation(None), error(false) {
    stack[0] = 0;
    stack[1] = 0;
}

void Calc::operation(const string& input) {
    if (input == "=") {
        if (currentOperation != None) {
            Operations::performOperation(*this);
            currentOperation = None;
        }
    } else {
        auto opIt = operations.find(input);
        if (opIt != operations.end()) {
            if (currentOperation != None) {
                Operations::performOperation(*this);
            }
            setCurrentOperation(input);
            opIt->second(*this);
        } else {
            throw invalid_argument("Invalid operation: " + input);
        }
    }
}

void Calc::clear() {
    Number = 0;
    stack[0] = 0;
    stack[1] = 0;
    currentOperation = None;
    error = false;
}

void Calc::updateNumber(double value) {
    Number = value;
    if (currentOperation == None) {
        stack[1] = value;
    } else {
        stack[0] = value;
    }
}

Op Calc::getCurrentOperation() const {
    return currentOperation;
}

void Calc::setCurrentOperation(const string& opStr) {
    if (opStr == "+") {
        currentOperation = AddOp;
    } else if (opStr == "-") {
        currentOperation = Sub;
    } else if (opStr == "×") {
        currentOperation = Mult;
    } else if (opStr == "÷") {
        currentOperation = Div;
    } else {
        currentOperation = None;
    }
}

void Calc::setNewOperandExpected() {
    stack[0] = Number;
    Number = 0;
}

void Calc::plusMinus() {
    if (error || currentOperation != None) return;
    stack[1] = -stack[1];
    Number = stack[1];
}

void Calc::Percent() {
    if (error) return;

    double operand = stack[1];
    double percentage = operand * 0.01;

    switch (currentOperation) {
        case AddOp: Number = stack[0] + (stack[0] * percentage); break;
        case Sub: Number = stack[0] - (stack[0] * percentage); break;
        case Mult: Number = stack[0] * percentage; break;
        case Div:
            if (percentage == 0) {
                setError(true);
                Number = 0;
            } else {
                Number = stack[0] / percentage;
            }
            break;
        default: Number = percentage; break;
    }

    stack[1] = Number;
}

double Calc::getStackValue(int index) {
    assert(index >= 0 && index < 2);
    return stack[index];
}

void Calc::setStackValue(int index, double value) {
    assert(index >= 0 && index < 2);
    stack[index] = value;
}

void Calc::setNumber(double value) { Number = value; }

double Calc::getNumber() const { return Number; }

bool Calc::getError() const { return error; }

void Calc::setError(bool value) { error = value; }