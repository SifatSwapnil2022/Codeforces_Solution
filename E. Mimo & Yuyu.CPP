#include <bits/stdc++.h>
using namespace std;

static inline void solve_one() {
    long long nRows;
    int nCols, q;
    cin >> nRows >> nCols >> q;

    // Track parity:
    // odd1  → whether column 1 has odd count
    // oddX  → how many columns != 1 currently have odd count
    bool odd1 = false;
    int  oddX = 0;

    // We only need to know if a column (!=1) is currently odd.
    // Use a hash map of parity for columns != 1.
    unordered_map<int, char> parity;
    parity.reserve(q * 2);

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c; // 'r' is irrelevant for the final decision

        if (c == 1) {
            odd1 = !odd1;
        } else {
            char &p = parity[c];   // default 0 if not present
            if (p == 0) {          // was even → becomes odd
                p = 1;
                ++oddX;
            } else {               // was odd → becomes even
                p = 0;
                --oddX;
            }
        }
    }

    if (nRows == 1) {
        // Only column 2 matters in the 1-row case
        // We don't have per-column 2 parity directly, so read from map
        bool odd_col2 = false;
        auto it = parity.find(2);
        if (it != parity.end()) odd_col2 = (it->second != 0);
        cout << (odd_col2 ? "Mimo\n" : "Yuyu\n");
        return;
    }

    // nRows >= 2: Mimo wins if ANY column != 1 has odd count
    cout << (oddX > 0 ? "Mimo\n" : "Yuyu\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve_one();
    return 0;
}
