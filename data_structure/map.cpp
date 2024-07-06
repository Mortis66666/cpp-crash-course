#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> dict;

    // Demonstrate use case
    // Insert key-value pairs into the map
    dict[1] = 10;
    dict[2] = 20;
    dict[3] = 30;

    // Access and print values using keys
    cout << "Value at key 1: " << dict[1] << endl;
    cout << "Value at key 2: " << dict[2] << endl;
    cout << "Value at key 3: " << dict[3] << endl;

    // Check if a key exists in the map
    if (dict.count(4) > 0) {
        cout << "Key 4 exists in the map" << endl;
    } else {
        cout << "Key 4 does not exist in the map" << endl;
    }

    // Iterate over the map and print all key-value pairs
    for (const auto& pair : dict) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}