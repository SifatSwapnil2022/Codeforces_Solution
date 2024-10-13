#include<bits/stdc++.h>
using namespace std;
int main(){
int test_cases;
cin>>test_cases;
while(test_cases--){
    int number,kumber;
    cin>>number>>kumber;
    if(kumber==number){
        for(int i=0;i<number;i++){
            cout<<"1 ";
        }cout<<endl;

    }
    else if(kumber==1){
         for(int i=0;i<=number;i++){
            cout<<i<<" ";
        }cout<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}
return 0;
}
