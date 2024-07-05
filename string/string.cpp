#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "Hello";
    cout << s + ", world!" << endl;  // Hello, world!
    cout << s << endl;               // Hello

    string s2 = s + ", world!";
    cout << s2 << endl;  // Hello, world!

    s.append(", world!");
    cout << s << endl;  // Hello, world!

    s[0] = 'B';
    cout << s << endl;

    s.at(0) = 'Z';
    cout << s << endl;

    cout << s.size() << endl;  // 13

    return 0;
}