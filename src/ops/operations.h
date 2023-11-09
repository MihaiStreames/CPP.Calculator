#ifndef CALCULATOR_OPERATIONS_H
#define CALCULATOR_OPERATIONS_H

#include <stdexcept>
#include <cmath>

using namespace std;

namespace Operations {
    // Arithmetic operations
    double Add(double a, double b);
    double Subtract(double a, double b);
    double Multiply(double a, double b);
    double Divide(double a, double b);

    // Other operations
    double Negation(double a);
}

#endif //CALCULATOR_OPERATIONS_H