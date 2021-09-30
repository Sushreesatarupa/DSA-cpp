### Problem Link : https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1#


### These 3 questions can be done with same DP logic : 
1. https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1# <br>
2. https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1# <br>
3. https://leetcode.com/problems/unique-paths/ <br>


Solution : ( Accepted ) 

> Just use 2D DP and return the m-1 and n-1 cell

```
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j] = 1;
                }else if(j==0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])% 1000000007; 
                }
            }
        }
        return dp[m-1][n-1]% 1000000007; 
    }
};
```
