#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,row,c;
        cin>>n>>m>>row>>c;
        ll ans = abs(  ((row-n)*m) + ((row-n)*(m-1))+(c-m) );
        cout<<ans<<endl;
    }
    return 0;

}
