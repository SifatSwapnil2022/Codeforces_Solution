#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> map_stick;

        while (n--) {
            int r;
            cin >> r;
            map_stick[r]++;

            int cnt = 0;
            for (auto iteration = map_stick.begin(); iteration != map_stick.end(); iteration++) {
                cnt += iteration->second / 3;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
