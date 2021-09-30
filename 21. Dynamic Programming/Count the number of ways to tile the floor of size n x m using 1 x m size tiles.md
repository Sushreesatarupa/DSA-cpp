### Question Link : https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1#


### Solution Video : https://www.youtube.com/watch?v=_c_R-uIi-zU&list=TLGGSPv0JY5jlnQxMjA5MjAyMQ


### SOLUTION : ( Accepted )

```
class Solution{
	public:
		int countWays(int n, int m)
	{
	    long long int dp[n+1] = {0};
	    for(int i=1;i<=n;i++){
	        if(i<m){
	            dp[i] = 1;
	        }else if(i==m){
	            dp[i] = 2;
	        }else{
	            dp[i] = (dp[i-1] + dp[i-m])%1000000007;
	        }
	    }
	    return dp[n];
	}
};
```
