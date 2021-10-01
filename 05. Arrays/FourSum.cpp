class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<tuple<int,int,int,int>>s;
        vector<vector<int>>ans;
        if(nums.size()<4)
            return ans;
        int a,b,c,d,n=nums.size();
        sort(nums.begin(),nums.end());
        for(a=0;a<n-3;a++){
            for(b=a+1;b<n-2;b++){
              c=b+1;
                d=n-1;
                while(c<d){
                int x=nums[a]+nums[b]+nums[c]+nums[d];
                if(x==target){
                    s.insert(make_tuple(nums[a],nums[b],nums[c],nums[d]));
                    c++;
                    d--;
                }
                
                else if(x<target)
                    c++;
                else
                    d--;
                }
            }
        }
        int size=s.size();
         vector<vector<int>> v(size,vector<int> (4));
        int i=0;
        for(auto it:s){
            v[i][0]=get<0>(it);
            v[i][1]=get<1>(it);
            v[i][2]=get<2>(it);
            v[i][3]=get<3>(it);
            i++;
        }
        return v;
    }
};
