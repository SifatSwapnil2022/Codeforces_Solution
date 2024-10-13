#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
 cin>>t;
 while(t--){
          int num;
          cin>>num;
          if(num%7 == 0){
                    cout<<num<<endl;
          }
          else if(num%7 != 0){
                              int a = num%7; //23%7 ==3
                              int b = 7-a; //7-3=4
                              int k = num%10; //3
                              if(k+b <10){
                                        num = num + b ; //23+4=27
                              }
                              else{
                                        num = num - a; //23-2
                              }
                               cout<< num << endl;

                }

       }
       return 0;
}

