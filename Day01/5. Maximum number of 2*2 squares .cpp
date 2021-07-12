/**
5. Maximum number of 2*2 squares 
Given the base (in units) of a right-angled isoceles traingle, find the maximum number of 2×2 squares that can fit in the triangle with given base.

Example 1:

Input: 8
Output: 6
Explanation:
Please refer below diagram for explanation.
squares-in-triangle

Example 2:

Input : 7
Output : 3
 
Your task :
You don't need to read input or print anything. Your task is to complete the function numberOfSquares() which takes the base of the triangle as input and returns the maximum number of squares that can be fit into the triangle with given base.
 
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
 
Constraints :
1 <= N <= 10^9
**/
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        //code here
        if (base%2 == 0)
        return (base)*(base-2)/8;
        else
        return(base -3)*(base-1)/8;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		long long int base;
		cin >> base;

        Solution ob;
		cout << ob.numberOfSquares(base) << "\n";

	}

	return 0;
}
  // } Driver Code Ends
