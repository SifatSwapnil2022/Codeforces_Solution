#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fs(kcv,bye)for(int kcv=0;kcv<bye;kcv++)
int main(){
int testcasenumbers;
cin>>testcasenumbers;
while(testcasenumbers--){
    ll numbers,cumbers,dumbers;
    cin>>numbers>>cumbers>>dumbers;
    vector<ll>vec_input(numbers*numbers);
    fs(i,numbers*numbers)
    cin>>vec_input[i];
    ll a = *min_element(input.begin(),input.end());
    unordered_map<ll,ll>map_1;
    for(auto m:vec_input)
        map_1[m]++;

    vector<vector<ll,ll>match_1(numbers,vector<ll>(numbers,0));
    match_1[0][0]=a;

    for(int i=0;i<numbers;i++){
        if(i!=0)
            match_1[i][0] = match_1[i-1][0]+cumbers;
        for(int j=0;j<numbers;j++){
            if(j!=0)
                match_1[i][j] = match_1[i][j-1]+dumbers;
        }
    }


    for(int i=0;i<numbers;i++)
        {
        for(int j=0;j<numbers;j++){
        int t = match_1[i][j];
    if(map_1.find(t) == map_1.end()){
        cout<<"NO"<<endl;
        return;
    }
    else{
        map_1[t]--;
        if(map_1[t]==0)
            map_1.erase(t);
    }

        }

        }
}
        return 0;


}
