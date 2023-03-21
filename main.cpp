#include <iostream>
#include "calculator.cpp"
using namespace std;

int main() {
    system("Clear");
    Calc a;
    string s = "q";
    while (s != "exit") {
        cout << "MATH:> ";
        cin >> s;
        a.Operation(s);
    }
    return 0;
}
