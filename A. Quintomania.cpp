#include<bits/stdc++.h>
using namespace std;
int main(){
    int the_test_cases;
    cin>>the_test_cases;
    while(the_test_cases--){
            int numMelodies;
            cin>>numMelodies;
            int flag=1;
            int arr_melodies[numMelodies];
            for(int i=0;i<numMelodies;i++){
                cin>>arr_melodies[i];
            }
            for(int i=0;i<numMelodies-1;i++){
                int ans = abs(arr_melodies[i]-arr_melodies[i+1]);
                if(ans != 5 && ans !=7){
                    flag=0;
                }
            }
            if(flag==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

    }
    return 0;
}
