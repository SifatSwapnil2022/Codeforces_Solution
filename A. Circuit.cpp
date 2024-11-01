#include <bits/stdc++.h>
using namespace std;

int main() {
    int the_test_cases;
    cin >> the_test_cases;
    while (the_test_cases--) {
        int lights;
        cin >> lights;
        vector<int> switches(2 * lights);
        int off = 0;
        int on = 0;

        for (auto &s : switches) {
            cin >> s;
        }

        for (const auto &s : switches) {
            if (s == 0) {
                off++;
            } else {
                on++;
            }
        }

        if (off == 0) {
            cout << "0 0" << endl;
        } else {
            int ans1 = off % 2;
            if (off >= on) {
                cout << ans1 << " " << on << endl;
            } else {
                cout << ans1 << " " << off << endl;
            }
        }
    }
    return 0;
}
