#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        long long arr[n];
        for(int i = 1 ; i<= n ; i++){
            cin>>arr[i];
        }
        sort(arr+1,arr+n+1);
        ll presum = 0, ans = k;
        for(int i=1;i<=n;i++){
            ll mul = (n-i+1);
            ll sum=mul*arr[i]+presum;
            presum += arr[i];
            if(sum>=k){
                break;
            }
            else{
                ans++;
            }
        }
        cout<<ans<<endl;


    }
    return 0;

}

