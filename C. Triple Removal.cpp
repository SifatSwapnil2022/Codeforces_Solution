#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                 // total test cases
    cin >> T;

    while (T--) {
        int N, Q;          // array size and number of queries
        cin >> N >> Q;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        // build prefix counters: zeros and ones
        vector<int> pref0(N + 1), pref1(N + 1);
        for (int i = 1; i <= N; ++i) {
            pref0[i] = pref0[i - 1] + (A[i - 1] == 0);
            pref1[i] = pref1[i - 1] + (A[i - 1] == 1);
        }

        // prefix for counting neighbors that are equal
        vector<int> sameNext(N + 1);
        for (int i = 1; i < N; ++i) {
            sameNext[i] = sameNext[i - 1] + (A[i] == A[i - 1]);
        }
        sameNext[N] = sameNext[N - 1];     // carry last prefix value

        while (Q--) {
            int L, R;     // 1-based indices for query range
            cin >> L >> R;

            int z = pref0[R] - pref0[L - 1];
            int o = pref1[R] - pref1[L - 1];

            // if zeros or ones not divisible by 3 → invalid
            if (z % 3 || o % 3) {
                cout << "-1\n";
                continue;
            }

            int segLen = R - L + 1;
            int part = segLen / 3;

            // check if at least one pair of adjacent equal numbers exists
            int adjPair = sameNext[R - 1] - sameNext[L - 1];

            cout << (adjPair ? part : part + 1) << "\n";
        }
    }
    return 0;
}
