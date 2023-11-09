#include "arithmetic.h"

void Operations::Add(Calc& calc) {
    calc.setNumber(calc.getStackValue(1) + calc.getStackValue(0));
    calc.setStackValue(1, calc.getNumber());
}

void Operations::Subtract(Calc& calc) {
    calc.setNumber(calc.getStackValue(1) - calc.getStackValue(0));
    calc.setStackValue(1, calc.getNumber());
}

void Operations::Multiply(Calc& calc) {
    calc.setNumber(calc.getStackValue(1) * calc.getStackValue(0));
    calc.setStackValue(1, calc.getNumber());
}

void Operations::Divide(Calc& calc) {
    if (calc.getStackValue(0) == 0) {
        calc.setError(true);
        calc.setNumber(0);
        return;
    }

    calc.setNumber(calc.getStackValue(1) / calc.getStackValue(0));
    calc.setStackValue(1, calc.getNumber());
}

void Operations::performOperation(Calc& calc) {
    if (calc.getError() || calc.getCurrentOperation() == None) {
        cout << "Error: Invalid operation" << endl;
        return;
    }

    cout << "Performing operation: " << calc.getCurrentOperation() << endl;
    switch (calc.getCurrentOperation()) {
        case AddOp: Add(calc); break;
        case Sub: Subtract(calc); break;
        case Mult: Multiply(calc); break;
        case Div: Divide(calc); break;
        default: break; // Handle unknown operation if necessary
    }
    cout << "Result: " << calc.getNumber() << endl;

    calc.setCurrentOperation("None");
    calc.setStackValue(0, 0);
}