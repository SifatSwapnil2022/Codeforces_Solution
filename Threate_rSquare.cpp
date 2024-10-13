#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,m,a,s,t;
cin>> n >> m >> a;
if(m%a == 0){

          s = m/a;
}
else
{
          s = m/a + 1;
}
if(n%a==0){
          t= n/a;
}
else{
          t=n/a+1;
}
cout << s*t <<endl;
return 0;
}
