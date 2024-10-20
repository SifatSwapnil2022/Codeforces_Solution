#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        ll sum = 0;
        cin >> n >> k;

        if (k == 1) {
            cout << n << endl; // Special case for base 1
        } else {
            while (n > 0) {
                sum += n % k; // Add the last digit in base k
                n /= k;       // Remove the last digit
            }
            cout << sum << endl;
        }
    }
    return 0;
}
