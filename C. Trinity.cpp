#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int the_test_cases;
    cin >> the_test_cases;
    while (the_test_cases--) {

            int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = n, l = 1, r = n;

    while (l <= r) {
        int mid = (l + r) / 2;
        bool found = false;

        if (mid == 1) {
            ans = min(ans, n - 1);
            l = mid + 1;
            continue;
        }


        for (int i = 0; i + mid - 1 < n; i++) {
            long long x = a[i] + a[i + 1];
            if (x > a[i + mid - 1]) {
                found = true;
                break;
            }
        }

        if (found) {
            ans = min(ans, n - mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;


    }
    return 0;
}