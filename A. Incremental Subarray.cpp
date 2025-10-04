#include <bits/stdc++.h>
using namespace std;

long long solve() {
    long long n;
    int m;
    cin >> n >> m;

    vector<long long> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    if (m == 1) {
        return n - a[0] + 1;
    }

    // Check strictly decreasing: a[0] > a[1] > ... > a[m-1]
    for (int i = 0; i + 1 < m; ++i) {
        if (a[i] <= a[i + 1]) {
            return 1;
        }
    }

    return n - a.back() + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
