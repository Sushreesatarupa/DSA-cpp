#include <bits/stdc++.h>

using namespace std;

int slidingWindow(int arr[], int n){
    int res = INT_MIN;
    for(int i=0 ; i<n ; i++){
        int sum = 0;
        for(int j = i ; j<i+3 ; j++){
            sum += arr[j];
        }
        res = max(sum , res);
    }
    return res;
}

int main()
{
    int n;
     cin>>n;
     int arr[n];
     for(int i = 0 ; i<n ; i++){
         cin>>arr[i];
     }
     cout<<slidingWindow(arr , n);

    return 0;
}
