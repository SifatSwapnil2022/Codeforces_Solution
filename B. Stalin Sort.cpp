#include <bits/stdc++.h>
using namespace std;

int main() {
    int the_test_cases;
    cin >> the_test_cases;

    while (the_test_cases--) {
        int the_number_stumps;
        cin >> the_number_stumps;

        vector<int> arr(the_number_stumps + 1);
        for (int i = 1; i <= the_number_stumps; i++) {
            cin >> arr[i];
        }

        int answer = INT_MAX;
        for (int i = 1; i <= the_number_stumps; i++) {
            int cnt = 0;
            for (int j = i + 1; j <= the_number_stumps; j++) {
                if (arr[j] > arr[i]) {
                    cnt++;
                }
            }
            answer = min(answer, cnt + (i - 1));
        }
        cout << answer << endl;
    }

    return 0;
}
