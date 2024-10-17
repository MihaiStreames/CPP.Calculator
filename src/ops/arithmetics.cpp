#include "operations.h"

namespace Operations {
    double Add(double a, double b) { return a + b; }

    double Subtract(double a, double b) { return a - b; }

    double Multiply(double a, double b) { return a * b; }

    double Divide(double a, double b) {
        if (b == 0) {
            return copysign(numeric_limits<double>::infinity(), a);
        }
        return a / b;
    }
}