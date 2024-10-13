/*#include<bits/stdc++.h>
using namespace std;
#define long long ll
int main(){
int test_cases;
cin>>test_cases;
while(test_cases--){
    int x,y,z;
    cin>>x>>y>>z;
    for(int i = 1 ; i*2<=z; i++){
        cout<<x-i<<' ' <<y<<endl;
                cout<<x+i<<' ' <<y<<endl;

    }
    if(z%1){
        cout<<x<<' '<<y<<endl;
    }

}

}
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;

        vector<pair<int, int>> points;

        // Generate k distinct points with center (xc, yc)
        for (int i = 0; i < k; ++i) {
            int x = xc + i;
            int y = yc;
            points.push_back({x, y});
        }

        // Output the points
        for (const auto& point : points) {
            cout << point.first << " " << point.second << endl;
        }
    }

    return 0;
}

