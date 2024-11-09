#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    cin>>t;
    while(t--){
        int numLights;
        cin>>numLights;
        int cnt0=0,cnt1=0;
        int arrStates[2*numLights];
        for( i=0;i<2*numLights;i++){
            cin>>arrStates[i];
            if(arrStates[i]==0)cnt0++;
        if(arrStates[i]==1)cnt1++;
        }


        if(arrStates==0)cout<<0<<" "<<0<<endl;
        else if(cnt0>=cnt1)cout<<cnt0%2<<" "<<cnt1<<endl;
        else cout<<cnt1%2<<" "<<cnt0<<endl;

    }
    return 0;

}
