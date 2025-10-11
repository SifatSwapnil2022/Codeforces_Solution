#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }


        sort(b, b + n);


        int count_Apple = 1;
        for (int i = 1; i < n; i++) {
            if (b[i] != b[i - 1]) {
                count_Apple++;
            }
        }

        cout << count_Apple << "\n";
    }

    return 0;
}
