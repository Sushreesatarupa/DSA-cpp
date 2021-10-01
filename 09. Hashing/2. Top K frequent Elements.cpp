/*
Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequency then the larger number should be given preference. 

Example 1:

Input:
nums = {1,1,1,2,2,3},
k = 2
Output: {1, 2}
Example 2:

Input:
nums = {1,1,2,2,3,3,3,4},
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 10^5
1<=A[i]<=10^5
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        map<int,int> freq;   //Storing the Frequency of each element in Hash Map
        for(int i=0; i<nums.size(); ++i) {
            freq[nums[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto i: freq) {
            vec.push_back({i.second,i.first});
        } 
        // Storing {Freqency, Element} pair in vector and sorting descending order to take top k elements
        sort(vec.rbegin(),vec.rend());
        vector<int> ans;
        int len=vec.size();
        for(int i=0; i<min(k,len); ++i) ans.push_back(vec[i].second);
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
