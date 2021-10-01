//Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

//Example 1:

 //       Input:
 //       N = 8
 //       A[] = {15,-2,2,-8,1,7,10,23}
 //       Output: 5
 //       Explanation: The largest subarray with
 //       sum 0 will be -2 2 -8 1 7.


//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(N).

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> map;   //map to store the sum of a subarray upto an index from start, with the index
        int sum = 0; 
        int len = 0;
        
        for (int i = 0; i < n; i++) {
        
        sum += A[i];
 
        if (A[i] == 0 && len == 0)
            len = 1;
        if (sum == 0)
            len = i + 1;
 

        if (map.find(sum) != map.end()) {   //if the same sum already exists uto a different point from the start, means that the elements between those 2 indices will have a 0 sum.
            len = max(len, i - map[sum]);
        }
        else {
            map[sum] = i;
        }
    }
 
    return len;
    }
};
