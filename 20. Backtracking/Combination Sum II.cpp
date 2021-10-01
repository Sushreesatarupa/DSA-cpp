class Solution {
public:
    vector<vector<int>>ans;
   vector<int>a;
    void solve(int indx,vector<int>& candidates,int sum)
    {
        if(sum==0)
        {
            ans.push_back(a);
            return;
        }
        for(int i=indx;i<candidates.size();i++)
        {
            if(i>indx&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>sum)
            {
                break;
            }
            a.push_back(candidates[i]);
            solve(i+1,candidates,sum-candidates[i]);
            a.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target);
        return ans;
        
    }
};