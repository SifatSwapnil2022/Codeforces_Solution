#include<bits/stdc++.h>
using namespace std;
int main(){

int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    if(n%2 !=0){
        cout<<"no"<<endl;
    }
    else{
        cout<<"yes"<<endl;
    }
    for(int i=1;i<=n/2;i++){
         if(n%2==0)
        cout<<"BB";

    else
        cout<<"AA";
    }
    cout<<endl;
}
return 0;
}
