#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int testcasenumbers;
    cin >> testcasenumbers;

    while (testcasenumbers--) {
        long long numbers, cumbers, dumbers;
        cin >> numbers >> cumbers >> dumbers;

        vector<long long> vec_input(numbers * numbers);
        for (int i = 0; i < numbers * numbers; i++)
            cin >> vec_input[i];

        long long a = *min_element(vec_input.begin(), vec_input.end());
        unordered_map<long long, long long> map_1;
        for (auto m : vec_input)
            map_1[m]++;

        vector<vector<long long>> match_1(numbers, vector<long long>(numbers, 0));
        match_1[0][0] = a;

        for (int i = 0; i < numbers; i++) {
            if (i != 0)
                match_1[i][0] = match_1[i - 1][0] + cumbers;
            for (int j = 0; j < numbers; j++) {
                if (j != 0)
                    match_1[i][j] = match_1[i][j - 1] + dumbers;
            }
        }

        bool valid = true;
        for (int i = 0; i < numbers; i++) {
            for (int j = 0; j < numbers; j++) {
                long long t = match_1[i][j];
                if (map_1.find(t) == map_1.end()) {
                    cout << "NO" << endl;
                    valid = false;
                    break;
                } else {
                    map_1[t]--;
                    if (map_1[t] == 0)
                        map_1.erase(t);
                }
            }
            if (!valid)
                break;
        }
        if (valid)
            cout << "YES" << endl;
    }
    return 0;
}

