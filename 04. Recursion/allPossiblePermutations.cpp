#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0){
            vector<vector<int>> baseCase;
            vector<int> base;
            baseCase.push_back(base);
            return baseCase;
        }
        vector<vector<int>> myans;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            vector<int> temp=nums;
            auto it=temp.begin()+i;
            temp.erase(it);
            vector<vector<int>> ans=permute(temp);
            for(vector<int> v:ans){
                v.push_back(x);
                myans.push_back(v);
            }
        }
        return myans;
}

int main(){
  int n;
  cout<<"Enter Size Of the array : ";
  cin>>n;
  vector<int> v;
  cout<<"Enter elements of array : ";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  vector<vector<int>> ans=permute(v);
  cout<<"All Possible Permutations are : \n";
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
