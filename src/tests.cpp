#include "expr-proc.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <exception>

// Utility function for comparing doubles with a tolerance
bool doubleEquals(double a, double b, double epsilon = 0.001) {
    return std::abs(a - b) < epsilon;
}

// Function to run a single test case
void runTest(const std::string& testExpression, double expectedResult, const std::string& testCase) {
    try {
        double result = ExprProc::process(testExpression);
        if (doubleEquals(result, expectedResult)) {
            std::cout << "PASSED: " << testCase << " -> " << testExpression << " = " << result << std::endl;
        } else {
            std::cout << "FAILED: " << testCase << " -> " << testExpression << " = " << result << " (expected " << expectedResult << ")" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "FAILED: " << testCase << " -> " << testExpression << " with exception: " << e.what() << std::endl;
    }
}

int main() {
    // Normal operations
    runTest("3+4", 7, "Addition test");
    runTest("12-5", 7, "Subtraction test");
    runTest("3*4", 12, "Multiplication test");
    runTest("20/5", 4, "Division test");

    // Operations with parentheses
    runTest("(3+4)*2", 14, "Parentheses test 1");
    runTest("2*(3+4)", 14, "Parentheses test 2");
    runTest("((2+3)*5)/5", 5, "Nested parentheses test");
    runTest("((20*5)/20)*-1", -5, "Harder parantheses test");


    // Edge cases
    runTest("1/0", numeric_limits<double>::infinity(), "Division by zero test");
    runTest("2*(2+)", numeric_limits<double>::quiet_NaN(), "Invalid expression test");
    runTest("2*+2", 4, "Unary plus test");
    runTest("2*-2", -4, "Unary minus test");

    return 0;
}
