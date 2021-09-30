#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long min(long long x,long long y) {
        return (x < y) ? x : y;
    }
 
    long long max(long long x, long long y) {
        return (x > y) ? x : y;
    }
	long long maxProduct(int *arr, int n) {
    if (n == 0) {
        return 0;
    }
    long long max_ending = arr[0], min_ending = arr[0];
    long long max_so_far = arr[0];
    for (int i = 1; i < n; i++)
    {
        long long temp1 = arr[i] * max_ending;
        long long temp2 = arr[i] * min_ending;
        max_ending = max(arr[i], max(temp1, temp2));
        min_ending = min(arr[i], min(temp1, temp2));
 
        max_so_far = max(max_so_far, max_ending);
    }
    return max_so_far;
	}
};

// { Driver Code Starts.

int main() {
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.maxProduct(arr, n);
    cout << ans << "\n";
    return 0;
}  // } Driver Code Ends