#include "calculator.h"

void TestAddition() {
    Calc calc;
    calc.Operation("3");
    calc.Operation("+");
    calc.Operation("2");
    calc.Operation("=");
    assert(calc.Number == 5);
}

void TestSubtraction() {
    Calc calc;
    calc.Operation("3");
    calc.Operation("-");
    calc.Operation("2");
    calc.Operation("=");
    assert(calc.Number == 1);
}

void TestMultiplication() {
    Calc calc;
    calc.Operation("3");
    calc.Operation("*");
    calc.Operation("2");
    calc.Operation("=");
    assert(calc.Number == 6);
}

void TestDivision() {
    Calc calc;
    calc.Operation("6");
    calc.Operation("/");
    calc.Operation("2");
    calc.Operation("=");
    assert(calc.Number == 3);
}

void TestDivisionByZero() {
    Calc calc;
    calc.Operation("6");
    calc.Operation("/");
    calc.Operation("0");
    calc.Operation("=");
    assert(calc.isError());
}

void TestSquareRoot() {
    Calc calc;
    calc.Operation("16");
    calc.Operation("Sqrt");
    const double epsilon = 0.00001;  // Acceptable margin of error
    assert(abs(calc.Number - 4) < epsilon);
}

void TestSquareRootNegativeNumber() {
    Calc calc;
    calc.Operation("-16");
    calc.Operation("Sqrt");
    assert(calc.isError());
}

void TestPercentAddition() {
    Calc calc;
    calc.Operation("100");
    calc.Operation("+");
    calc.Operation("10");
    calc.Operation("%");
    calc.Operation("=");
    assert(calc.Number == 110);
}

void TestPercentSubtraction() {
    Calc calc;
    calc.Operation("100");
    calc.Operation("-");
    calc.Operation("10");
    calc.Operation("%");
    calc.Operation("=");
    assert(calc.Number == 90);
}

void TestClear() {
    Calc calc;
    calc.Operation("100");
    calc.Operation("Clear");
    assert(calc.Number == 0);
}

void RunTests() {
    TestAddition();
    TestSubtraction();
    TestMultiplication();
    TestDivision();
    TestDivisionByZero();
    TestSquareRoot();
    TestSquareRootNegativeNumber();
    TestPercentAddition();
    TestPercentSubtraction();
    TestClear();
    cout << "All tests passed!" << endl;
}

int main() {
    RunTests();
    return 0;
}