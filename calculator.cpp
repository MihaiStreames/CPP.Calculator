#include <iostream>
using namespace std;

class Calc {
public:
    Calc();
    double Number; // Answer
    int Operation(string); // Work with Client Code
    int stack_spot; // Hold the spot in Stack
private:
    double s2f(string); // Convert string to double
    double stack[3]; // Stack that holds data
    void Add();
    void Sub();
    void Mult();
    void Div();
    void Sqrt();
    void Equal();
    void Clear();
    double SquareRoot(double);
    double Abs(double);
};

Calc::Calc() {
    stack_spot = 0;
    Number = 0;
}

int Calc::Operation(string n) {
    if (n == "Sqrt") {
        Sqrt();
        stack_spot = 1;
        return -1;
    }
    else if (n == "Clear") {
        Clear();
        return -1;
    }
    else if (stack_spot == 0) {
        stack[0] = s2f(n);
        stack_spot++;
        Number = stack[0];
    }
    else if (stack_spot == 1) {
        if (n == "+") {
            n = "1";
        }
        else if (n == "-") {
            n = "2";
        }
        else if (n == "*") {
            n = "3";
        }
        else if (n == "/") {
            n = "4";
        }
        stack[stack_spot] = s2f(n);
        stack_spot++;
    }
    else if (stack_spot == 2) {
        stack[2] = s2f(n);
        Equal();
        stack_spot = 1;
        cout << stack[0] << endl;
    }
}

void Calc::Sqrt() {

}

void Calc::Clear() {
    stack_spot = 0;
    Number = 0;
    stack[0] = 0;
}

double Calc::s2f(string str) {
    const char* strC;
    strC = str.c_str();
    return atof(strC);
}

void Calc::Equal() {
    if (stack[1] == 1) {
        Add();
    }
    else if (stack[1] == 2) {
        Sub();
    }
    else if (stack[1] == 3) {
        Mult();
    }
    else if (stack[1] == 4) {
        Div();
    }
}

void Calc::Add() {
    Number = stack[0] + stack[2];
    stack[0] = Number;
}

void Calc::Sub() {
    Number = stack[0] - stack[2];
    stack[0] = Number;
}

void Calc::Mult() {
    Number = stack[0] * stack[2];
    stack[0] = Number;
}

void Calc::Div() {
    if (stack[2] != 0) {
        Number = stack[0] / stack[2];
        stack[0] = Number;
    }
}