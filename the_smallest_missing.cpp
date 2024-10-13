#include<bits/stdc++.h>
using namespace std;

int find_Smallest_Missing(int arr[], int low, int high)
{

    if (low > high) {
        return low;
    }

    int mid = low + (high - low) / 2;


    if (arr[mid] == mid) {
        return find_Smallest_Missing(arr, mid + 1, high);
    }
    else {

        return find_Smallest_Missing(arr, low, mid - 1);
    }
}

int main()
{   int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int low = 0, high = n - 1;

    cout<<"The smallest missing element is %d"<<find_Smallest_Missing(a, low, high);

    return 0;
}
