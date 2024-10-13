#include<bits/stdc++.h>
using namespace std;
int main(){
 int a,b,cnt=0,cnt1=0;
 cin>>a>>b;
 int arr[a];
 for(int i = 0;i<a;i++){
          cin>>arr[i];
          if(arr[i]<=b){
                    cnt++;
          }
          else{
                    cnt1 +=2;
          }
 }
 cout<<cnt+cnt1;

}
