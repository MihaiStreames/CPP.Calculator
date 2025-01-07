#ifndef CALCULATOR_EXPR_PROC_H
#define CALCULATOR_EXPR_PROC_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

class ExprProc {
public:
    static double process(const string& expression);

private:
    static vector<string> tokenize(const string& expression);
    static vector<string> shunting_yard(const vector<string> &tokens);
    static double evaluate_postfix(const vector<string> &postfix);
    static int get_precedence(const string& op);
    static bool is_left_associative(const string& op);
    static bool is_operator(const string& token);
    static bool is_function(const string& token);

};

#endif //CALCULATOR_EXPR_PROC_H