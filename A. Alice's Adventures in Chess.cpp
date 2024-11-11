#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int x = 0, y = 0;

    // Repeat path up to 10 times
    for (int t = 0; t < 10; t++) {
        for (auto j : s) {
            if (j == 'N') {
                y++;
            } else if (j == 'E') {
                x++;
            } else if (j == 'S') {
                y--;
            } else if (j == 'W') {
                x--;
            }

            // Check if the current position matches the target
            if (x == a && y == b) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    // If the target is not reached after 10 iterations
    cout << "NO" << endl;
}

int main(){
int t;
cin>>t;
while(t--){
    solve();
}
    return 0;
}
