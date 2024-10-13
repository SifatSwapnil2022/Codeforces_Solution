#include<bits/stdc++.h>
using namespace std;
/*char arr[105][105];
int main(){
          int n,m;
          cin>>n>>m;
          for(int i =0;i<n;i++){
                    for(int j=0;j<m;j++){
                              cin>>arr[i][j];
                    }
          }

           for(int i=0;i<n;i++){
                    for(int j=0;j<m-1;j++){
                              if(arr[i][j] != arr[i][j+1]){
                                        cout<<"NO"<<endl;
                                         return 0;
                              }
                    }
           }

                    //check valid column
                     for(int i =0;i<m;i++){
                              for(int j=0;j<n-1;j++){
                                 if(arr[j][i] != arr[j+1][i]){
                                        cout<<"NO"<<endl;
                                        return 0;
                              }
                    }
          }
    cout <<"YES"<<endl;
     return 0;



}*/
char arr[105][105];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> arr[i][j];
    // check for valid row //
    for(int i=0; i<n; ++i){
        for(int j=0; j<m-1; ++j){
            if(arr[i][j] != arr[i][j+1]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    // check valid column //
    for(int i=0; i<m; ++i){
        for(int j=0; j<n-1; ++j){
            if(arr[j][i] == arr[j+1][i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return (0);
}

