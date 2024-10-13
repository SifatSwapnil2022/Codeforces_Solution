#include<bits/stdc++.h>
using namespace std;


void run(){
        long long n, k, x;
        cin >> n >> k >> x;


        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];


        sort(a.begin(), a.end());

        long long sum = 0;


        long long in = n - x;
        for (long long i = 0; i < n; i++) {
            if (i < in)
                sum += a[i];
            else
                sum -= a[i];
        }


        long long ans = sum;


        for (long long i = n - 1; i >= n - k; i--) {
            if (i >= in) {
                sum += a[i];


                if (in - 1 >= 0)
                    sum -= 2 * a[in - 1];


                in--;


                ans = max(sum, ans);
            }
        }


        cout << ans << endl;
    }

    int main() {
    long long t;
    cin >> t;

    while (t--) {
 run();
    }
}

