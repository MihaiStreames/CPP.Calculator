#include "sqrt.h"

double Operations::SquareRoot(double n, bool& errorFlag) {
    if (n < 0) {
        errorFlag = true;
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

void Operations::Sqrt(Calc& calc) {
    double valueToSqrt = (calc.getCurrentOperation() == None) ? calc.getStackValue(1) : calc.getStackValue(0);
    bool errorFlag = calc.getError();
    double sqrtResult = SquareRoot(valueToSqrt, errorFlag);
    calc.setError(errorFlag);

    if (calc.getError()) {
        calc.setNumber(0);
    } else {
        calc.setNumber(sqrtResult);
    }

    calc.setStackValue(0, sqrtResult);
    calc.setStackValue(1, sqrtResult);
}