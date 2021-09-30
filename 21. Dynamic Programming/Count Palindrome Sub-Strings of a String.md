# Question Link : https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1#


## Video Solution : 

SOLUTION : ( ACCEPTED )
> Problem can be faced because gfg don't consider single string as palindromic string but leetcode does, so we need to change in last condtion if(g!=0 && dp[i][j] == true)
> 
```
int CountPS(char S[], int N)
{
    
    bool dp[N][N];
    int count =0;
    
    for(int g = 0; g < N; g++){
        
        for(int i = 0, j = g; j < N; i++, j++){
            if(g==0){
                dp[i][j] = true;
            }else if(g==1){
                if(S[i] == S[j]){
                    dp[i][j] = true;
                }else {
                    dp[i][j] = false;
                }
            }else {
                if(S[i]==S[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                }else {
                    dp[i][j] = false;
                }
            }
        
            if(g!=0 && dp[i][j]==true){
                count++;
            }
        }
    }
    return count;
}
```
