#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
 ll t;
cin>>t;
while(t--){
          char a [11] [11];
          for( ll i = 0 ; i<=10 ; i++){
                    for( ll j = 1 ; j<=10 ; j++){
                              cin>>a[i][j];
                    }
          }
          ll k = 0 ;
          for( ll i = 0 ; i<=10 ; i++){
                    for( ll j = 1 ; j<=10 ; j++){
                              if(a[i][j] == 'X'){
                                        if(i<=5){
                                                  if(j<=5) k+=min(i,j);
                                                  else k+=min(i,11-j);
                                        }
                                        else {
                                                  if(j<=5)k+=min(11-i,j);
                                                  else k+=min(11-i,11-j);
                                        }
                              }
                    }
          }
          cout<<k<<endl;
  }
}




