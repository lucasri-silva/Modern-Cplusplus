#include <iostream>
#include "BigInt.hpp"

using namespace std;

int main() {
    BigInt a("250");
    BigInt b("105");

    BigInt c = a + b;
    BigInt d = a - b;
    BigInt e = a * b;
    BigInt f = a / b;

    cout << "a + b = " << c.toString() << endl;
    cout << "a - b = " << d.toString() << endl;
    cout << "a * b = " << e.toString() << endl;
    cout << "a / b = " << f.toString() << endl;

    return 0;
}