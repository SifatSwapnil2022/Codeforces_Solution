#include<bits/stdc++.h>
using namespace std;
int main(){
    int the_test_cases;
    cin>>the_test_cases;
    while(the_test_cases--){
        int the_number_stumps;
        cin>>the_number_stumps;
    int width,height;

    int max1,max2;
    max1=max2= -1e9;
    for(int i =0; i<the_number_stumps  ;i++){
        cin>>width>>height;
         max1 = max(max1,width);
         max2 = max(max2,height);
    }
    int answer = 2*(max1 + max2);
    cout<<answer<<endl;
    }
    return 0;

}
