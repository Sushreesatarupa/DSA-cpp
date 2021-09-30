/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Example 1:
Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.

Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ n ≤ 10^3
1 ≤ A[i] ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);    // Sorting Array 
        int ans=0;
        for(int i=1; i<=(n-2); ++i) {
            int l=0, r=n-1;
            // Fixing A[i] and find A[l] and A[r] which sums upto target X. 
            while(l<=r and l<i and r>i) {
                int sum=A[l]+A[i]+A[r];
                if(sum<=X) {
                    if(sum==X) ans++;
                    l++;
                }
                else r--;
            }
        }
        return (ans>0?1:0);
    }
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

