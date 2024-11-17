#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int cnt = 0;


        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }


        map<int, int> ans;
        for (int i = 0; i < n; i++) {
            ans[a[i]]++;
        }

        for (pair<int, int> elem : ans) {
            cnt += elem.second / 2;
        }

        cout << cnt << endl;
    }

    return 0;
}

