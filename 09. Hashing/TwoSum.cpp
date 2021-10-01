class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> remainders;// key: remainder, value: index
        vector<int> res(2);
        for(unsigned int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(remainders.find(nums[i]) == remainders.end()){
                remainders[rem] = i;
            }else{
                res[1] = i;
                res[0] = remainders[nums[i]];
                return res;
            }
        }
        return res;
    }
};