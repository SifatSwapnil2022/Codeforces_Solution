#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int x, y, z;
        cin >> x >> y >> z;

        bool possible = true;

        for (int bit = 0; bit < 31; bit++) {
            int a = (x >> bit) & 1;
            int b = (y >> bit) & 1;
            int c = (z >> bit) & 1;

            int ones = a + b + c;
            if (ones == 2) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
