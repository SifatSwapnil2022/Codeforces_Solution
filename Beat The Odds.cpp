#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
int t;
cin>>t;
while(t--){

int n;
cin>>n;
int x, even = 0 , odd = 0 ;
for(int i=0; i<n ; i++){
          cin>>x;
          if(x%2 == 0 )even++;
          else odd++;
}
cout<<min(even,odd)<<endl;


}






}
