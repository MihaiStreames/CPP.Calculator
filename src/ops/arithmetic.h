#ifndef CALCULATOR_ARITHMETIC_H
#define CALCULATOR_ARITHMETIC_H

#include "../calculator.h"

namespace Operations {
    void Add(Calc& calc);
    void Subtract(Calc& calc);
    void Multiply(Calc& calc);
    void Divide(Calc& calc);
    void performOperation(Calc& calc);
}

#endif //CALCULATOR_ARITHMETIC_H