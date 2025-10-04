#include <bits/stdc++.h>
using namespace std;

void run() {
    int len;
    cin >> len;

    vector<int> arr(len);
    for (int i = 0; i < len; i++) cin >> arr[i];

    // sort and remove duplicates
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int u = arr.size();            // number of unique elements
    int ans = u + max(0, u - 1);    // same as 2*u - 1 for u>=1
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) run();

    return 0;
}
