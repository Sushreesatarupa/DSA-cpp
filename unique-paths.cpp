#include<bits/stc++.h>
using namespace std;

int uniquePaths(int m, int n) {
        vector< vector<int>>dp(m,vector<int>(n));
        for(int i = 0;i<m;i++){
            dp[i][n-1] = 1;
        }
        for(int j = 0;j<n;j++){
            dp[m-1][j] = 1;
        }
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j]= dp[i+1][j] + dp[i][j+1];
            }
        }
        
        
        return dp[0][0];
}


int main(){
    cout<< uniquePaths(3, 4);
    return 0;
}
