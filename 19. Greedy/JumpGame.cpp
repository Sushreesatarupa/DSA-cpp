/* 

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105

*/

#include<bits/stdc++.h>

using namespace std; 

//Algorithm
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = 0;
        for(int i = 0;i < nums.size(); i++){
            if (steps  <  0)
                return false;
            steps = max(steps, nums[i]) - 1;
        }    
        return true;
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter the number of Array Elements: ";
        cin >> n;
        cout << "Input " << n << " elements: ";
        vector<int> v(n);
        for (auto &it : v) {
            cin >> it;
        }
        Solution ob;
        if(ob.canJump(v) == true) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}