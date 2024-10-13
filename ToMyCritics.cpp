#include<bits/stdc++.h>

using namespace std;

int main(){
          #define int long long

          int test;
          cin>>test;
          while(test--){
          int a,b,c;
          cin >>a >>b >>c;
          if(a+b >= 10 || b+c >=10 || a+c >=10 ){
                    cout<< "YES\n" ;
          }
          else{
                    cout<<"No\n" ;
          }
 }
 return 0;
}

