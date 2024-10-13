#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){

          string s ;
          cin>>s;  //ABBA
          int n = s.size(); //4
          int a = 0, b = 0 , cnt = 0;
          for(int i=0 ; i<s.size();i++){
                    if(s[i]=='A')cnt++ ;//1
                    else b++;
                    if(s[i] == s[i+1] && s[i] == 'B'){
                              f= 1;
                    }
          }


}
}
