## Question : Consecutive 1's not allowed
 https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1#

## Videos : 
Sumit Sir https://www.youtube.com/watch?v=nqrXHJWMeBc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=18

Solution : (Accepted on gfg)

```
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    int ocz = 1;
	    int oco = 1;
	    
	    for(int i=2;i<=n;i++)
	    {
	        int ncz = oco%1000000007;
	        int nco = ocz + oco%1000000007;
	        
	        ocz = ncz%1000000007;
	        oco = nco%1000000007;
	        
	    }
	    
	    return (ocz+oco)%1000000007;
	}
};
```
