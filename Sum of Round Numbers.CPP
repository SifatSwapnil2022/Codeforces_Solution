#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
                    vector<int>answer;
          int n,x=1;
          cin>>n;
          while(n){
                    x=x*10;
                    int modulas = n%x;
                    if(modulas){
                              answer.push_back(modulas);
                    }
          n=n-modulas;
          }
          cout<<answer.size()<<endl;
          for(int i=0; i<answer.size();i++){
                    cout<<answer[i]<<" ";
          }
          cout<<endl;
}

}
