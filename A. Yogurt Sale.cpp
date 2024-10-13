#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
int testcasenumbers;
cin>>testcasenumbers;
while(testcasenumbers--){
    int numberof_yogurts,a_burles,b_burles;
    int sum_burles=0;

    cin>>numberof_yogurts>>a_burles>>b_burles;
    if(numberof_yogurts%2 !=0){

    sum_burles+=a_burles;
       numberof_yogurts--;
    }
   ll c1=numberof_yogurts*a_burles;
   ll c2=(numberof_yogurts/2)*b_burles;
   ll answer_yogurts = min(c1,c2)+sum_burles;
   cout<<answer_yogurts<<endl;
}
return 0;
}
