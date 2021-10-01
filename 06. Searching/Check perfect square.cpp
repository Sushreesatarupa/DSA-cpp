/*
Given a positive integer n, check if it is perfect square or not.
NOTE: Try to solve the question using only addition and subtraction operation.

Example 1:

Input: n = 35
Output: 0 
Explanation: 35 is not perfect
square because sqrt(35) = 5 but
5*5 !=35.
Example 2:

Input: n = 49
Output: 1
Explanation: sqrt(49) = 7 and 
7*7 = 49, Hence 49 is perfect square. 

Your Task:  
You dont need to read input or print anything. Complete the function isPerfectSquare() which takes n as input parameter and returns 1 if n is a perfect square else return 0.

Expected Time Complexity: O(sqrt(n))
Expected Auxiliary Space: O(1)

Constraints:
1<= n <=105
*/

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int isPerfectSquare(long long int n){
        // code here
        if(n<=0)return 0;
        int m=1;
        while(m<=n){
            if((m*m)==n)return 1;
            m++;
        }return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.isPerfectSquare(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
