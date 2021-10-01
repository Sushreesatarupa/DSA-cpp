#include<bits/stc++.h>
using namespace std;

long long int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //each cell of dp array tells total no of unique ways from that cell to lat celll(mat[m-1][n-1])
        vector< vector<long long int>>dp(m,vector<long long int>(n));
        
        dp[m-1][n-1] = mat[m-1][n-1]^1;    //last cell, destination, if there is obstacle then no way to reach there, no unique path
        
        //last row        
        for(int j = n-2;j>=0;j--){
            if(mat[m-1][j]==1 or dp[m-1][j+1]==0){  //if there is obstacle, or there is no way to reach adjacent cell, then there is also no way to reach that cell, thsu dp[m-1][j] = 0; 
                dp[m-1][j] = 0;
            }
            else{
                dp[m-1][j] = 1;
            }

        }
        
         //last column      
        for(int i = m-2;i>=0;i--){
            if(mat[i][n-1]==1 or dp[i+1][n-1]==0){  //if there is obstacle, or there is no way to reach adjacent cell, then there is also no way to reach that cell, thsu dp[i][n-1] = 0; 
                dp[i][n-1] = 0;
            }
            else{
                dp[i][n-1] = 1;
            }

        }
        
        
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                if(mat[i][j]==1){    //cell have obstacle
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        
        return dp[0][0];
    }

int main(){
    cout<< uniquePaths({{0,0,0},{0,1,0},{0,0,0}});
    return 0;
}
