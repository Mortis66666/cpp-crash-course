#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 42;
    string b = "Hello, World!";

    // Outputs a and b space-separated
    cout << a << " " << b << endl;

    // Faster
    cout << a << "\n";

    // Set as x-decial
    double c = 3.14159265358979323846;
    cout << fixed << setprecision(10) << c << endl;  // 3.1415926536

    return 0;
}