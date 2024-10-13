#include<bits/stdc++.h>
using namespace std;


    void run(){
        long long lower_limit = 0, upper_limit = LLONG_MAX;

        int n;
        cin >> n;
        set<long long> values_set;

        while (n--) {
            int a;
            cin >> a;
            long long value;
            cin >> value;
            if (a == 1) {
                lower_limit = max(lower_limit, value);
            } else if (a == 2) {
                upper_limit = min(upper_limit, value);
            } else {
                values_set.insert(value);
            }
        }

        long long result_count = upper_limit - lower_limit + 1;
        for (auto val : values_set) {
            if (val >= lower_limit && val <= upper_limit) {
                result_count--;
            }

        }
        if (result_count < 0) {
            result_count = 0;
        }
        cout << result_count << endl;
    }
    int main() {
    int t;
    cin >> t;

    while (t--) {

           run();


    }
    }

