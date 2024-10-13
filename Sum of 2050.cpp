#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
ll t;
cin>>t;
while(t--){
           ll n;
           cin>>n;
           int cnt = 0 ;
           while(n>=2050){
                    cnt++;
                    ll x=2050;
                    while(x<=n){
                              x*=10;
                    }
                    x/=10;
                    n= n-x;

           }
           if(n!=0)cout<<-1<<endl;
           else cout<<cnt<<endl;
}
return 0;


}
