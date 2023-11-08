#include "calculator.h"

Calc::Calc() : Number(0), currentOperation(None), error(false) {
    stack[0] = 0;
    stack[1] = 0;
}

void Calc::Operation(const string& input) {
    if (input == "Sqrt") {
        Sqrt();
        return;
    } else if (input == "Clear") {
        Clear();
        return;
    } else if (input == "=") {
        PerformOperation();
        currentOperation = None;
        return;
    } else if (input == "+/-") {
        PlusMinus();
        return;
    }

    try {
        // Handle numeric input; check for a number or a decimal point
        if (isdigit(input[0]) || input[0] == '.' || (input[0] == '-' && input.size() > 1)) {
            if (currentOperation == None) {
                stack[1] = stod(input); // If no operation, set stack[1]
            } else {
                stack[0] = stod(input); // If there's an operation, set stack[0]
            }
            Number = stack[1]; // Update display number
            return;
        }
    } catch (const invalid_argument& e) {
        // Handle invalid argument
        error = true;
        return;
    } catch (const out_of_range& e) {
        // Handle out of range
        error = true;
        return;
    }

    // Handle setting the current operation
    if (input == "+") {
        currentOperation = AddOp;
    } else if (input == "-") {
        currentOperation = Subtract;
    } else if (input == "*") {
        currentOperation = Multiply;
    } else if (input == "/") {
        currentOperation = Divide;
    } else if (input == "%") {
        currentOperation = PercentOp;
        Percent(); // Calculate percentage immediately
    }
}

void Calc::Sqrt() {
    if (error) return;
    Number = SquareRoot(stack[0]);
    stack[0] = Number;
}

void Calc::Clear() {
    Number = 0;
    stack[0] = 0;
    stack[1] = 0;
    currentOperation = None;
    error = false;
}

void Calc::PerformOperation() {
    if (error) return;

    switch (currentOperation) {
        case AddOp: Add(); break;
        case Subtract: Sub(); break;
        case Multiply: Mult(); break;
        case Divide: Div(); break;
        default: break;
    }

    // After the operation, prepare for a new calculation or repeat the operation
    stack[0] = Number;
}

void Calc::PlusMinus() {
    if (error || currentOperation != None) return;
    stack[1] = -stack[1];
    Number = stack[1];
}

void Calc::Percent() {
    if (error) return;

    // Apply percentage based on the previous operation
    double result = stack[1] * (stack[0] / 100.0);
    if (currentOperation == AddOp || currentOperation == Subtract) {
        // If we're adding or subtracting, we should apply the percentage to the existing number
        result = (currentOperation == AddOp) ? stack[1] + result : stack[1] - result;
    }

    Number = result;
    stack[1] = Number; // Save the result as the next operand
    currentOperation = None; // Reset the operation
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