#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,d;
    cin>>n>>d;
    ll b[n];
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    ll countt = 0;
    for(ll i=1;i<n;i++){
        if(b[i-1] >= b[i]){
            countt += ((b[i-1]-b[i])/d+1) ;
            b[i] += ((b[i-1]-b[i])/d+1) *d;
        }
    }
    cout<<countt<<endl;
    return 0;

}
