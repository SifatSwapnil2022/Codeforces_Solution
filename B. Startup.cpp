#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll the_test_cases;
    cin >> the_test_cases;
    while (the_test_cases--) {
        ll shelvesMachine_n, availableBottles_k;
        cin >> shelvesMachine_n >> availableBottles_k;

        vector<pair<int, int>> vectors(availableBottles_k);

        for (int i = 0; i < availableBottles_k; i++) {
            cin >> vectors[i].first >> vectors[i].second;
        }

        unordered_map<int, ll> machineBottles;

        for (const auto& pair : vectors) {
            int machine = pair.first;
            int bottles = pair.second;
            machineBottles[machine] += bottles;
        }

        vector<ll> totalBottles;
        for (const auto& entry : machineBottles) {
            totalBottles.push_back(entry.second);
        }

        sort(totalBottles.begin(), totalBottles.end(), greater<ll>());

        ll ans = 0;
        for (int i = 0; i < min(shelvesMachine_n, (ll)totalBottles.size()); i++) {
            ans += totalBottles[i];
        }

        cout << ans << endl;
    }
    return 0;
}
