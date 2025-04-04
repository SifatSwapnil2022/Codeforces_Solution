#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        ll x;
        cin >> n >> k >> x;
        vector<ll> arr(n);
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        vector<ll> m(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            m[i] = m[i - 1] + arr[i - 1];
        }

        ll x_value = k * sum - x;
        ll ans = 0;

        if (x_value < 0) {
            cout << 0 << endl;
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (m[j] > x_value) continue;

            ll max_m = (x_value - m[j]) / sum;
            ll count_m = min((ll)k, max_m + 1);
            ans += count_m;
        }

        cout << ans << endl;
    }
    return 0;
}
