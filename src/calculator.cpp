#include "calculator.h"
#include "expr-proc.h"

Calc::Calc() : current_input(), error_flag(false) {}

void Calc::input(const string& input) {
    if (input != "=") {
        current_input += input;
    } else {
        try {
            Number = ExprProc::process(current_input);
        } catch (const exception& e) {
            error_flag = true;
        }
        current_input.clear();
    }
}

void Calc::clear() {
    current_input.clear();
    error_flag = false;
}