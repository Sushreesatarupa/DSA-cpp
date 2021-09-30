Problem Statement -: Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.
Example 1:

Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.

Example 2:

Input:
N = 6
Arr = {9, 4, 20, 3, 10, 5}
k = 33
Output: 2
Explaination: 
Subarrays : arr[0...2], arr[2...4] have sum
exactly equal to 33.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 2*104
-103 ≤ Arr[i] ≤ 103
-107 ≤ k ≤ 107

//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Driver Code Ends

//Driver Code Starts
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
// Driver Code Ends

//Solution:-
class Solution{
    public:
    int findSubArraySum(int arr[], int N, int k)
    {
        // code here
        unordered_map<int,int>mp;
        int currsum=0,count=0;
        for(int i=0;i<N;i++){
            currsum+=arr[i];
            if(currsum==k)
                count++;
            if(mp.find(currsum-k)!=mp.end())
                count+=mp[currsum-k];
            mp[currsum]++;
        }
        return count;
    }
};
