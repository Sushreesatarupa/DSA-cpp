// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        
        return (n>>k)%2;
        // Your code here
        // It can be a one liner logic!! Think of it!!

		/* Another alternative way
		solution:
		return n & (1<<k);

		Logic:
		(k's numbering starting with 0)
		To get the k-th bit, generate a mask of 00000s with just kth bit set 
		for example for k = 3, mask  = 0000 1000 
		To get this mask, you simply left shift 1 by k,
		mask = 1 << k
		Finally, answer will be AND of number & mask, 
		it will return 1 if that bit is set in number 
		otherwise 0
		*/
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;//taking testcases
	while(t--)
	{
	    long long n;
	    cin>>n;//input n
	    int k;
	    cin>>k;//bit number k
	    Solution obj;
	    if(obj.checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}  // } Driver Code Ends
