class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n)
        {
            int sum=(-1)*nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[j]+nums[k]<sum)
                {
                    j++;
                }
                else if(nums[j]+nums[k]>sum)
                {
                    k--;
                }
                else
                {
                    v.push_back({nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                }
            }
            i++;
            while(i<n && nums[i]==nums[i-1])
                i++;
        }
        return v;
    }
};