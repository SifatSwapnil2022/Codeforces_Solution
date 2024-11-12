// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
   int t;
   cin>>t;
   while(t--){
       int n,b,c;
       cin>>n>>b>>c;
       if(b==0){
           if(c== n-2 || c==n-1){
               cout<<n-1<<endl;
           }
           else if(c<n-2){
               cout<<"-1"<<endl;
               
           }
           else{
               cout<<n<<endl;
           }
       }
       int ans = n-max((n-c+b-1)/b,OLL);
       cout<<ans<<endl;
   }
   return 0;
}
