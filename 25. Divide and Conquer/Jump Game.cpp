```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0, prev = 0, count = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
			
            cur = max(cur, i+nums[i]);
			
            if(cur >= nums.size()-1)
                return count+1;
			
            if(i == prev)
            {
                prev = cur;
                ++count;
            }
        }
        return count;
    }
};
```
