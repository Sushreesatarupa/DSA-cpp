/**
1. Plus One 
Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most significant digit is first element of array.
 

Example 1:

Input: 
N = 3
arr[] = {1, 2, 4}
Output: 
1 2 5
Explanation:
124+1 = 125, and so the Output
Example 2:

Input: 
N = 3
arr[] = {9,9,9}
Output: 
1 0 0 0
Explanation:
999+1 = 1000, and so the output

Your Task:
You don't need to read input or print anything. You only need to complete the function increment() that takes an integer N, and an array arr of size N as input and returns a list of integers denoting the new number which we get after adding one to the number denoted by the array arr.


Expected Time Complexity:  O(N)
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= N <= 105
0 <= arri <= 9


**/
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
	    
	    // Here you have run the loop from 0 to n but consider the case when the number is say , 9 9 9, then the answer should be
	    // 1 0 0 0 and here the size of array must be n+1 that is 4. However the loop run till i<3 which will output 1 0 0 only.
	    // So I think you must update it. Happy Coding !!!😊
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
