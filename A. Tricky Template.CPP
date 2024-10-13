#include<bits/stdc++.h>
using namespace std;

int main(){
    int test_case;
    cin>>test_case;

    while(test_case--){
            int n;
            cin>>n;
            string a,b,c;
            cin>>a>>b>>c;
            int ans = 0;
            for(int i=0;i<n;i++){
                if(a[i]!=c[i] &&  b[i] !=c[i]){
                    ans = 1;
                    break;
                }

            }
            if(ans==1){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
             }
    return 0;

}

