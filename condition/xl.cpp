#include <bits/stdc++.h>

using namespace std;

bool single_bit_rng() { return rand() % 2; }

struct XL {
   public:
    inline void go_insane() { cout << "I'm going insane!" << endl; }

    inline void go_crazy() { cout << "I'm going crazy!" << endl; }
};

int main() {
    // Too less for a commit so I decided to do some random shit

    srand((unsigned)time(NULL));

    XL xl;
    bool chiikawa_exist = single_bit_rng();

    cout << (chiikawa_exist ? "Chiikawa is here" : "Chiikawa is not here")
         << endl;

    if (chiikawa_exist) {
        xl.go_insane();
    } else {
        xl.go_crazy();
    }

    return 0;
}