/*
Take two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as 
it shows in both arrays and you may return the result in any order.

Input: nums1 = [1,2,2,1] nums2 = [2,2]

Output: 2, 2
*/

#include <bits/stdc++.h>
using namespace std;

void intersect(vector<int>& nums1, vector<int>& nums2) {
    // sort the two vectors
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> nums;
          int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                nums.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if(nums1[i]<nums2[j]){
                ++i;
            }
            else{
                ++j;
            }
        }
    
        for(int k=0; k<nums.size(); k++){
            cout << nums[k] << " ";
            }
   
        
    }

int main(){
    int n,m,a;
    cin>>n>>m;  //take the size of vector g1 and vector g2
  

    vector<int> g1;
    vector<int> g2;

  
    for (int i = 1; i <=n ; i++){
        cin>>a;
        g1.push_back(a);
    }

     for (int i = 1; i <= m; i++){
        cin>>a;
        g2.push_back(a); 
     }
    
    //Call the function forthe intersectio of g1 and g2
    intersect(g1, g2);

     return 0;
}