#include "expr-proc.h"
#include "ops/operations.h"

vector<string> ExprProc::tokenize(const string& expression) {
    vector<string> tokens;
    string token;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isspace(c)) continue;

        if (isdigit(c) || c == '.') {
            token.push_back(c);
            while (i + 1 < expression.length() && (isdigit(expression[i + 1]) || expression[i + 1] == '.')) {
                token.push_back(expression[++i]);
            }
            tokens.push_back(token);
            token.clear();
        }
        else if (strchr("+-*/()", c)) {
            // Unary operator check
            if ((c == '+' || c == '-') && (tokens.empty() || tokens.back() == "(" || strchr("+-*/", tokens.back().back()))) {
                if (c == '-') {
                    token.push_back(c);
                }
            } else {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                tokens.emplace_back(1, c);
            }
        }
        else {
            throw invalid_argument("Invalid character in expression");
        }
    }
    return tokens;
}

int ExprProc::get_precedence(const std::string &op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0; // Precedence for non-operators
}

bool ExprProc::is_left_associative(const string& op) {
    return true;
}

vector<string> ExprProc::shunting_yard(const vector<string> &tokens) {
    stack<string> operator_stack;
    vector<string> queue;

    for (const string& token : tokens) {
        if (isdigit(token[0])) {
            queue.push_back(token);
        } else if (token == "(") {
            operator_stack.push(token);
        } else if (token == ")") {
            while (!operator_stack.empty() && operator_stack.top() != "(") {
                queue.push_back(operator_stack.top());
                operator_stack.pop();
            }
            if (!operator_stack.empty()) {
                operator_stack.pop();
            }
        } else {
            while (!operator_stack.empty() && get_precedence(operator_stack.top()) >= get_precedence(token) && is_left_associative(token)) {
                queue.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(token);
        }
    }

    while (!operator_stack.empty()) {
        queue.push_back(operator_stack.top());
        operator_stack.pop();
    }
    return queue;
}

double ExprProc::evaluate_postfix(const vector<string> &postfix) {
    stack<double> stack;

    for (const string &token: postfix) {
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            stack.push(stod(token));
        } else {  // The token is an operator
            if (stack.size() < 2) {
                throw invalid_argument("Invalid expression.");
            }

            double operand2 = stack.top(); stack.pop();
            double operand1 = stack.top(); stack.pop();
            double result = 0;

            if (token == "+") {
                result = Operations::Add(operand1, operand2);
            } else if (token == "-") {
                result = Operations::Subtract(operand1, operand2);
            } else if (token == "*") {
                result = Operations::Multiply(operand1, operand2);
            } else if (token == "/") {
                result = Operations::Divide(operand1, operand2);
            }
            stack.push(result);
        }
    }

    if (stack.size() != 1) {
        throw invalid_argument("Invalid expression.");
    }
    return stack.top();
}

double ExprProc::process(const string& expression) {
    auto tokens = tokenize(expression);
    auto postfix = shunting_yard(tokens);
    return evaluate_postfix(postfix);
}