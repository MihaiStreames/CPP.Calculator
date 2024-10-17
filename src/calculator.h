#ifndef CALC_H
#define CALC_H

#include <iostream>

using namespace std;

class Calc {
public:
    Calc();

    void input(const string& input);
    void clear();

    double get_number() const { return Number; }
    string get_current_input() const { return current_input; }
    bool has_error() const { return error_flag; }
    void clear_error() { error_flag = false; }

private:
    string current_input;
    string current_operation;
    double Number;
    bool error_flag;

};

#endif // CALC_H