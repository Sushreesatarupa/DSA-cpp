#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,0));

    for(int i=0;i<=word1.size();i++){
        for(int j=0;j<=word2.size();j++){
            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }else{
                // dp[i][j] -> word1[0..i-1] and word2[0..j-1]
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
    }

    return dp[word1.size()][word2.size()];
}

int main(){
  cout<<minDistance("my name is ishika", "my is ish");
}
