
#include<bits/stdc++.h>
using namespace std;
int main(){
    int the_test_cases;
    cin>>the_test_cases;
    while(the_test_cases--){

     string s;
    cin >> s;

        int n = s.size();
        int cnt_num = 0;

        auto matchesPattern = [&](int i) {
            return (i >= 0 && i + 3 < n && s.substr(i, 4) == "1100");
        };

        for (int i = 0; i <= n - 4; ++i)
            cnt_num += matchesPattern(i);

        int q;
        cin >> q;

        for (int j = 0; j < q; ++j) {


            int i;
            char c;
            cin >> i >> c;
            --i;

            for (int j = i - 3; j <= i; ++j)
                cnt_num -= matchesPattern(j);

            s[i] = c;

            for (int j = i - 3; j <= i; ++j)
                cnt_num += matchesPattern(j);

            cout << (cnt_num > 0 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
