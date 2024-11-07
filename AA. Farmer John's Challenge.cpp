#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const ll mod=1e9+7;
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        if(n == k) {
            for(ll i = 0 ; i < n ; i++) {
                cout<<"1 ";
            }
        }
        else { // n > k
            if(k >= 2)
                cout<<-1;
            else {
                for(ll i = 1 ; i <= n ; i++) {
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;     
 }
