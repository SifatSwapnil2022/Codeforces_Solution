#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
        int n;
        cin>>n;
        int min1 = 0, max1 = 0 , min2 = 0 ,max2 = 0;
        for(int i = 0; i<n ; i++){
          int x,y;
          cin>>x>>y;
          min1 = min (min1,x);
          max1 = max (max1,x);
           min2 = min (min2,y);
          max2 = max (max2,y);
        }
          ll ans = (abs(min1)*2  + max1*2) + (abs(min2)*2 + max2*2);
          cout << ans << endl;
}
}
