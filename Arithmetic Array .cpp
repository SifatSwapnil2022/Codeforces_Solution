#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
          int n;
          cin>>n;
          int arra[n+2];
          int sum=0;
          for(int i=0; i<n ; i++){
                    cin>>arra[i];
                    sum +=arra[i];
          }
          if(sum == n){
                    cout<<0<<endl;
          }
          else if(sum<n){
                    cout<<1<<endl;
          }
          else{
                    cout<<sum-n<<endl;
              }
          }
          return 0;
     }
