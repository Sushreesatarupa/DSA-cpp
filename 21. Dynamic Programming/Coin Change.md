## Question : https://practice.geeksforgeeks.org/problems/coin-change2448/1

## Videos : 
Sumit Sir : https://www.youtube.com/watch?v=l_nR5X9VmaI&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=13 <br>
Mine (logic) : https://youtu.be/E0M3ykpH5cQ

Solution : 

```
class Solution
{
  public:
    long long int count( int arr[], int len, int sum )
    {
       
    long long int dp[sum+1] = {0};
    dp[0]=1;
        //memset(dp,0,sizeof(dp));
    for(int i=0;i<len;i++){
        for(int j=arr[i];j<sum+1;j++){
        dp[j]+= dp[j-arr[i]];
           }
       }
        return dp[sum];
    }
};
```

SOLUTION : ( ADITYA VERMA ) 

```
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        
        long long int t[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            t[i][0] = 1;
        }
        for(int j=1;j<=n;j++)
        {
            t[0][j] = 0;
            }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]<=j)
                {
                    t[i][j] = t[i-1][j] + t[i][j-S[i-1]];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[m][n];
    }
};
```
