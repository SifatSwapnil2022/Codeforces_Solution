#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--)
    {
        string a,b;
        cin>>a>>b;
        int ans = 0;
        for(int i=0;i<b.length();i++){
            int s=i;
            int cnt=0;
           for(int j=0;i<a.length();j++) {
            if(a[j]==b[s]){
                s++;
                cnt++;
            }
           }
           ans = max(ans,cnt);
        }
        cout <<ans;

    }
    return 0;
}
